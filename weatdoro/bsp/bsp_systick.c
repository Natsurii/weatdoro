#include "bsp_systick.h"

volatile uint32_t g_system_ticks = 0;

/**
 * @brief 
 * 
 */
void sys_tick_handler(void){
    g_system_ticks++;
}

/**
 * @brief 
 * 
 */
void bsp_systick_init(void) {
    systick_set_clocksource(STK_CSR_CLKSOURCE_AHB);
    
    // Reload count (84MHz * 10us) - 1 = 839
    systick_set_reload((uint32_t)(rcc_ahb_frequency / 100000) - 1);
    systick_clear();

    systick_counter_enable();
    systick_interrupt_enable();
}

/**
 * @brief 
 * 
 * @param ticks 
 */
void delay(uint32_t ticks){
    uint32_t start_tick = g_system_ticks;

    while((uint32_t)(g_system_ticks - start_tick) < ticks){
    // WAIT
    };

}

/**
 * @brief 
 * 
 * @param seconds 
 */
inline void delay_in_s(double seconds){
    delay(SEC_TO_TICKS(seconds));
}