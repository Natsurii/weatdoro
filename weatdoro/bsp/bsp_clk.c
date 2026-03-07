#include "bsp_clk.h"

/**
 * @brief 
 * 
 */
void bsp_clk_init(void){
    rcc_clock_setup_pll(BSP_CLK_AHB_FREQ_CFG);
}