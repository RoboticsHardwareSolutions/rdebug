#ifndef __DWT_H
#define __DWT_H

#define DWT_CYCCNT *(volatile unsigned long*) 0xE0001004
#define DWT_CONTROL *(volatile unsigned long*) 0xE0001000
#define SCB_DEMCR *(volatile unsigned long*) 0xE000EDFC

void               dwt_timer_enable(void);
unsigned long      dwt_timer_get_ticks(void);
float              dwt_timer_get_time_sec(unsigned long long prev);


#endif
