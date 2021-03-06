// SPDX-License-Identifier: GPL-2.0+
/*
 * Copyright (C) 2011 Samsung Electronics
 */

#include <common.h>
#include <asm/io.h>
#include <asm/gpio.h>
#include <asm/arch/cpu.h>
#include <asm/arch/mmc.h>
#include <asm/arch/clk.h>
#include <asm/arch/periph.h>
#include <asm/arch/pinmux.h>
#include <usb.h>

u32 get_board_rev(void)
{
	return 0;
}

int exynos_init(void)
{
    /**
     * 配置MMC时钟
     */
    set_mmc_clk(2, 0x4);
    set_mmc_clk(4, 0x2);

    /**
     * 配置USB驱动
     */
    gpio_request(EXYNOS4X12_GPIO_M33, "USB3503A Connect");
    gpio_request(EXYNOS4X12_GPIO_M24, "USB3503A Reset");
    gpio_request(EXYNOS4X12_GPIO_C01, "DM9621");

    return 0;
}

int board_usb_init(int index, enum usb_init_type init)
{
    gpio_direction_output(EXYNOS4X12_GPIO_M33, 0);
    gpio_direction_output(EXYNOS4X12_GPIO_C01, 0);
    gpio_direction_output(EXYNOS4X12_GPIO_M24, 0);
    gpio_direction_output(EXYNOS4X12_GPIO_M24, 1);
    gpio_direction_output(EXYNOS4X12_GPIO_C01, 1);
    gpio_direction_output(EXYNOS4X12_GPIO_M33, 1);
    return 0;
}

#ifdef CONFIG_BOARD_EARLY_INIT_F
int exynos_early_init_f(void)
{
	return 0;
}
#endif
