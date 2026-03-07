#ifndef BSP_SYSTICK_H
#define BSP_SYSTICK_H
#include <stdint.h>
#include <libopencm3/cm3/systick.h>
#include <libopencm3/stm32/rcc.h>
#include <libopencm3/cm3/nvic.h>


#define TICK_PERIOD_US 10
#define SEC_TO_TICKS(s) ((uint32_t)(((s) * 1000000.0 / TICK_PERIOD_US) + 0.5))

extern volatile uint32_t g_system_ticks;

void sys_tick_handler(void);
void bsp_systick_init(void);
void delay(uint32_t ticks);
inline void delay_in_s(double seconds);
#endif  /* BSP_SYSTICK_H */