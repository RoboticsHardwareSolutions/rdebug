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
