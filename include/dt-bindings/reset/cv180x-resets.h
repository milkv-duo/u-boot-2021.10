/* SPDX-License-Identifier: GPL-2.0+ */
/*
 * Copyright (C) Cvitek Co., Ltd. 2019-2020. All rights reserved.
 *
 * File Name: cvi_template.h
 * Description:
 */

#ifndef __DT_BINDINGS_RST_CV180X_H__
#define __DT_BINDINGS_RST_CV180X_H__

#define RST_MAINRST_AP	0
#define RST_SECONDRST_AP	1
#define RST_DDR	2
#define RST_H264C	3
#define RST_JPEG	4
#define RST_H265C	5
#define RST_VIPSYS	6
#define RST_TDMA	7
#define RST_TPU	8
#define RST_TPUSYS	9
#define RST_TSM	10
#define RST_USB	11
#define RST_ETH0	12
#define RST_ETH1	13
#define RST_NAND	14
#define RST_EMMC	15
#define RST_SD0	16
#define RST_SD1	17
#define RST_SDMA	18
#define RST_I2S0	19
#define RST_I2S1	20
#define RST_I2S2	21
#define RST_I2S3	22
#define RST_UART0	23
#define RST_UART1	24
#define RST_UART2	25
#define RST_UART3	26
#define RST_I2C0	27
#define RST_I2C1	28
#define RST_I2C2	29
#define RST_I2C3	30
#define RST_I2C4	31
#define RST_PWM0	32
#define RST_PWM1	33
#define RST_PWM2	34
#define RST_PWM3	35
#define RST_PWM4	36
#define RST_PWM5	37
#define RST_PWM6	38
#define RST_PWM7	39
#define RST_SPI0	40
#define RST_SPI1	41
#define RST_SPI2	42
#define RST_SPI3	43
#define RST_GPIO0	44
#define RST_GPIO1	45
#define RST_GPIO2	46
#define RST_EFUSE	47
#define RST_WDT	48
#define RST_AHBRST_ROM	49
#define RST_SPIC	50
#define RST_TEMPSEN	51
#define RST_SARADC	52
#define RST_PCIERST_CDMA	53
#define RST_PCIERST_SMMU	54
#define RST_PCIERST_PCIE	55
#define RST_PCIERST_FABS	56
#define RST_PCIERST_IRQ	57
#define RST_COMBORST_PHY0	58
#define RST_COMBORST_PHY1	59
#define RST_USB1	60
#define RST_SPIRST_NAND	61
#define RST_SE	62
#define RST_RTCRST_SWRST_ONLY	63
#define RST_CPUCORE0	64
#define RST_CPUCORE1	65
#define RST_CPUCORE2	66
#define RST_CPUCORE3	67
#define RST_DSIPHY	68
#define RST_DSIPHYRST_APB	69
#define RST_CSIPHY0	70
#define RST_CSIPHY0RST_APB	71
#define RST_CSIPHY1	72
#define RST_CSIPHY1RST_APB	73
#define RST_UART4	74
#define RST_GPIO3	75
#define RST_SYSTEM	76
#define RST_TIMER	77
#define RST_TIMER0	78
#define RST_TIMER1	79
#define RST_TIMER2	80
#define RST_TIMER3	81
#define RST_TIMER4	82
#define RST_TIMER5	83
#define RST_TIMER6	84
#define RST_TIMER7	85
#define RST_WGN0	86
#define RST_WGN1	87
#define RST_WGN2	88
#define RST_KEYSCAN	89
#define RST_SPIC1	90
#define RST_AUDDAC	91
#define RST_AUDDACRST_APB	92
#define RST_AUDADC	93
#define RST_AUDADCRST_APB	94
#define RST_VCSYS	95
#define RST_ETHPHY	96
#define RST_ETHPHYRST_APB	97
#define RST_AUDSRC	98
#define RST_AUTO_CLEAR_CPUCORE0	99
#define RST_AUTO_CLEAR_CPUCORE1	100
#define RST_AUTO_CLEAR_CPUCORE2	101
#define RST_AUTO_CLEAR_CPUCORE3	102
#define RST_AUTO_CLEAR_MAINRST_AP	103
#define RST_AUTO_CLEAR_SECONDRST_AP	104

#define CLK_RST_A53		0
#define CLK_RST_50M_A53		1
#define CLK_RST_AHB_ROM		2
#define CLK_RST_AXI_SRAM	3
#define CLK_RST_DDR_AXI		4
#define CLK_RST_EFUSE		5
#define CLK_RST_APB_EFUSE	6
#define CLK_RST_AXI_EMMC	7
#define CLK_RST_EMMC		8
#define CLK_RST_100K_EMMC	9
#define CLK_RST_AXI_SD		10
#define CLK_RST_SD		11
#define CLK_RST_100K_SD		12
#define CLK_RST_500M_ETH0	13
#define CLK_RST_AXI_ETH0	14
#define CLK_RST_500M_ETH1	15
#define CLK_RST_AXI_ETH1	16
#define CLK_RST_AXI_GDMA	17
#define CLK_RST_APB_GPIO	18
#define CLK_RST_APB_GPIO_INTR	19
#define CLK_RST_GPIO_DB		20
#define CLK_RST_AXI_MINER	21
#define CLK_RST_AHB_SF		22
#define CLK_RST_SDMA_AXI	23
#define CLK_RST_SDMA_AUD	24
#define CLK_RST_APB_I2C		25
#define CLK_RST_APB_WDT		26
#define CLK_RST_APB_JPEG	27
#define CLK_RST_JPEG_AXI	28
#define CLK_RST_AXI_NF		29
#define CLK_RST_APB_NF		30
#define CLK_RST_NF		31
#define CLK_RST_APB_PWM		32
#define CLK_RST_RV		33
#define CLK_RST_APB_SPI		34
#define CLK_RST_TPU_AXI		35
#define CLK_RST_UART_500M	36
#define CLK_RST_APB_UART	37
#define CLK_RST_APB_I2S		38
#define CLK_RST_AXI_USB		39
#define CLK_RST_APB_USB		40
#define CLK_RST_125M_USB	41
#define CLK_RST_33K_USB		42
#define CLK_RST_12M_USB		43
#define CLK_RST_APB_VIDEO	44
#define CLK_RST_VIDEO_AXI	45
#define CLK_RST_VPP_AXI		46
#define CLK_RST_APB_VPP		47
#define CLK_RST_AXI1		48
#define CLK_RST_AXI2		49
#define CLK_RST_AXI3		50
#define CLK_RST_AXI4		51
#define CLK_RST_AXI5		52
#define CLK_RST_AXI6		53

#endif /* _DT_BINDINGS_RST_CV180X_H_ */
