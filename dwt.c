#include "dwt.h"
#include "stm32f1xx_hal.h"
/******************************************************************/
/*

MAX TIME 22 sec !!!!!!!!!!

int64_t tic = dwt_timer_get_ticks();
       do something
float time = dwt_timer_get_time_sec(tic);

*/
/******************************************************************/
void dwt_timer_enable(void)
{
    SCB_DEMCR |= CoreDebug_DEMCR_TRCENA_Msk;  // alowing  use DWT
    DWT_CYCCNT = 0;
    DWT_CONTROL |= DWT_CTRL_CYCCNTENA_Msk;
}

unsigned long dwt_timer_get_ticks(void)
{
    return DWT_CYCCNT;
}

float dwt_timer_get_time_sec(unsigned long long prev)
{
    int64_t delta = (int64_t) DWT_CYCCNT - prev;
    if (delta < 0)
        delta += 0xFFFFFFFF;

    return (float) delta / SystemCoreClock;
}

void dwt_delay_us(volatile unsigned long long us)
{
    unsigned long long initial_ticks = DWT->CYCCNT;
    unsigned long long ticks         = (HAL_RCC_GetHCLKFreq() / 1000000);
    us *= ticks;
    while ((DWT->CYCCNT - initial_ticks) < us - ticks)
    {
    };
}

void dwt_delay_ms(volatile unsigned long long ms)
{
    uint32_t initial_ticks = DWT->CYCCNT;
    uint32_t ticks         = (HAL_RCC_GetHCLKFreq() / 1000);
    ms *= ticks;
    while ((DWT->CYCCNT - initial_ticks) < ms)
    {
    };
}