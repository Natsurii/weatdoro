#ifndef BSP_CLK_H
#define BSP_CLK_H

#include <libopencm3/stm32/rcc.h>

#define BSP_CLK_AHB_FREQ_CFG (&rcc_hsi_configs[RCC_CLOCK_3V3_84MHZ])
void bsp_clk_init(void);
#endif /* BSP_CLK_H */