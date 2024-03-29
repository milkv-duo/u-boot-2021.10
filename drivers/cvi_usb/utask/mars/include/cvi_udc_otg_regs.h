/* SPDX-License-Identifier: GPL-2.0+ */
/* linux/arch/arm/plat-s3c/include/plat/regs-otg.h
 *
 * Copyright (C) 2004 Herbert Poetzl <herbert@13thfloor.at>
 *
 * Registers remapping:
 * Lukasz Majewski <l.majewski@samsumg.com>
 */

#ifndef __ASM_ARCH_REGS_USB_OTG_HS_H
#define __ASM_ARCH_REGS_USB_OTG_HS_H

/* USB2.0 OTG Controller register */
struct cvi_usbotg_phy {
	u32 phypwr;
	u32 phyclk;
	u32 rstcon;
};

/* Device Logical IN Endpoint-Specific Registers */
struct cvi_dev_in_endp {
	u32 diepctl;
	u8  res1[4];
	u32 diepint;
	u8  res2[4];
	u32 dieptsiz;
	u32 diepdma;
	u32 dtxfsts;
	u32 diepdmab;
};

/* Device Logical OUT Endpoint-Specific Registers */
struct cvi_dev_out_endp {
	u32 doepctl;
	u8  res1[4];
	u32 doepint;
	u8  res2[4];
	u32 doeptsiz;
	u32 doepdma;
	u8  res3[4];
	u32 doepdmab;
};

struct ep_fifo {
	u32 fifo;
	u8  res[4092];
};

/* USB2.0 OTG Controller register */
struct cvi_usbotg_reg {
	/* Core Global Registers */
	u32 gotgctl; /* OTG Control & Status */
	u32 gotgint; /* OTG Interrupt */
	u32 gahbcfg; /* Core AHB Configuration */
	u32 gusbcfg; /* Core USB Configuration */
	u32 grstctl; /* Core Reset */
	u32 gintsts; /* Core Interrupt */
	u32 gintmsk; /* Core Interrupt Mask */
	u32 grxstsr; /* Receive Status Debug Read/Status Read */
	u32 grxstsp; /* Receive Status Debug Pop/Status Pop */
	u32 grxfsiz; /* Receive FIFO Size */
	u32 gnptxfsiz; /* Non-Periodic Transmit FIFO Size */
	u8  res0[20];
	u32 gsnpsid;
	u8  res1[192];
	u32 dieptxf[15]; /* Device Periodic Transmit FIFO size register */
	u8  res2[1728];
	/* Device Configuration */
	u32 dcfg; /* Device Configuration Register */
	u32 dctl; /* Device Control */
	u32 dsts; /* Device Status */
	u8  res3[4];
	u32 diepmsk; /* Device IN Endpoint Common Interrupt Mask */
	u32 doepmsk; /* Device OUT Endpoint Common Interrupt Mask */
	u32 daint; /* Device All Endpoints Interrupt */
	u32 daintmsk; /* Device All Endpoints Interrupt Mask */
	u8  res4[224];
	struct cvi_dev_in_endp in_endp[16];
	struct cvi_dev_out_endp out_endp[16];
	u8  res5[256];
	u32 pcgcctl; /* Power and Clock Gating Control Register */
	u8  res6[508];
	struct ep_fifo ep[16];
};

/*===================================================================== */
/*definitions related to CSR setting */

/* SNPSID*/
#define CVI_CORE_REV_4_20a     0x4f54420a
#define CVI_CORE_REV_MASK      0x0000ffff
/* CVI_UDC_OTG_GOTGCTL */
#define B_SESSION_VALID		(0x1<<19)
#define A_SESSION_VALID		(0x1<<18)

/* CVI_UDC_OTG_GAHBCFG */
#define PTXFE_HALF			(0<<8)
#define PTXFE_ZERO			(1<<8)
#define NPTXFE_HALF			(0<<7)
#define NPTXFE_ZERO			(1<<7)
#define MODE_SLAVE			(0<<5)
#define MODE_DMA			(1<<5)
#define BURST_SINGLE			(0<<1)
#define BURST_INCR			(1<<1)
#define BURST_INCR4			(3<<1)
#define BURST_INCR8			(5<<1)
#define BURST_INCR16			(7<<1)
#define GBL_INT_UNMASK			(1<<0)
#define GBL_INT_MASK			(0<<0)

/* CVI_UDC_OTG_GRSTCTL */
#define AHB_MASTER_IDLE		(1u<<31)
#define CORE_SOFT_RESET		(0x1<<0)
#define CSFTRST_DONE            (0x1<<29)

/* CVI_UDC_OTG_GINTSTS/CVI_UDC_OTG_GINTMSK core interrupt register */
#define INT_RESUME			(1u<<31)
#define INT_DISCONN			(0x1<<29)
#define INT_CONN_ID_STS_CNG		(0x1<<28)
#define INT_RESETDET			(0x1<<23)
#define INT_OUT_EP			(0x1<<19)
#define INT_IN_EP			(0x1<<18)
#define INT_ENUMDONE			(0x1<<13)
#define INT_RESET			(0x1<<12)
#define INT_SUSPEND			(0x1<<11)
#define INT_EARLY_SUSPEND		(0x1<<10)
#define INT_NP_TX_FIFO_EMPTY		(0x1<<5)
#define INT_RX_FIFO_NOT_EMPTY		(0x1<<4)
#define INT_SOF			(0x1<<3)
#define INT_DEV_MODE			(0x0<<0)
#define INT_HOST_MODE			(0x1<<1)
#define int_gout_nak_eff			(0x01<<7)
#define int_gin_nak_eff			(0x01<<6)

#define FULL_SPEED_CONTROL_PKT_SIZE	8
#define FULL_SPEED_BULK_PKT_SIZE	64

#define HIGH_SPEED_CONTROL_PKT_SIZE	64
#define HIGH_SPEED_BULK_PKT_SIZE	512

#define RX_FIFO_SIZE			(1024)
#define NPTX_FIFO_SIZE			(64)
#define PTX_FIFO_SIZE			(384)

#define DEPCTL_TXFNUM_0		(0x0<<22)
#define DEPCTL_TXFNUM_1		(0x1<<22)
#define DEPCTL_TXFNUM_2		(0x2<<22)
#define DEPCTL_TXFNUM_3		(0x3<<22)
#define DEPCTL_TXFNUM_4		(0x4<<22)

/* Enumeration speed */
#define USB_HIGH_30_60MHZ		(0x0<<1)
#define USB_FULL_30_60MHZ		(0x1<<1)
#define USB_LOW_6MHZ			(0x2<<1)
#define USB_FULL_48MHZ			(0x3<<1)

/* CVI_UDC_OTG_GRXSTSP STATUS */
#define OUT_PKT_RECEIVED		(0x2<<17)
#define OUT_TRANSFER_COMPLELTED	(0x3<<17)
#define SETUP_TRANSACTION_COMPLETED	(0x4<<17)
#define SETUP_PKT_RECEIVED		(0x6<<17)
#define GLOBAL_OUT_NAK			(0x1<<17)

/* CVI_UDC_OTG_DCTL device control register */
#define RMTWKUPSIG		(0x1<<0)
#define SOFT_DISCONNECT		(0x1<<1)
#define CGNPINNAK			(0x1<<8)
#define SGOUTNAK			(0x1<<9)
#define CGOUTNAK			(0x1<<10)
#define PWRONPRGDONE			(0x1<<11)
#define DCTL_TSTCTL_SHIFT		(4)
#define DCTL_TSTCTL_MASK		(0x7<<DCTL_TSTCTL_SHIFT)

/* CVI_UDC_OTG_DAINT device all endpoint interrupt register */
#define DAINT_OUT_BIT			(16)
#define DAINT_MASK			(0xFFFF)

/* CVI_UDC_OTG_DIEPCTL0/DOEPCTL0 device control IN/OUT endpoint 0 control register */
#define DEPCTL_EPENA			(0x1<<31)
#define DEPCTL_EPDIS			(0x1<<30)
#define DEPCTL_SETD1PID		(0x1<<29)
#define DEPCTL_SETD0PID		(0x1<<28)
#define DEPCTL_SNAK			(0x1<<27)
#define DEPCTL_CNAK			(0x1<<26)
#define DEPCTL_STALL			(0x1<<21)
#define DEPCTL_TYPE_BIT		(18)
#define DEPCTL_TYPE_MASK		(0x3<<18)
#define DEPCTL_CTRL_TYPE		(0x0<<18)
#define DEPCTL_ISO_TYPE		(0x1<<18)
#define DEPCTL_BULK_TYPE		(0x2<<18)
#define DEPCTL_INTR_TYPE		(0x3<<18)
#define DEPCTL_USBACTEP		(0x1<<15)
#define DEPCTL_NEXT_EP_BIT		(11)
#define DEPCTL_MPS_BIT			(0)
#define DEPCTL_MPS_MASK		(0x7FF)

#define DEPCTL0_MPS_64			(0x0<<0)
#define DEPCTL0_MPS_32			(0x1<<0)
#define DEPCTL0_MPS_16			(0x2<<0)
#define DEPCTL0_MPS_8			(0x3<<0)
#define DEPCTL_MPS_BULK_512		(512<<0)
#define DEPCTL_MPS_INT_MPS_16		(16<<0)

#define DIEPCTL0_NEXT_EP_BIT		(11)


/* CVI_UDC_OTG_DIEPMSK/DOEPMSK device IN/OUT endpoint common interrupt mask register */
/* CVI_UDC_OTG_DIEPINTn/DOEPINTn device IN/OUT endpoint interrupt register */
#define BACK2BACK_SETUP_RECEIVED	(0x1<<6)
#define INEPNAKEFF			(0x1<<6)
#define INTKNEPMIS			(0x1<<5)
#define INTKN_TXFEMP			(0x1<<4)
#define NON_ISO_IN_EP_TIMEOUT		(0x1<<3)
#define CTRL_OUT_EP_SETUP_PHASE_DONE	(0x1<<3)
#define CTRL_IN_EP_TIMEOUT		(0x1<<3)
#define AHB_ERROR			(0x1<<2)
#define EPDISBLD			(0x1<<1)
#define TRANSFER_DONE			(0x1<<0)

#define USB_PHY_CTRL_EN0                (0x1 << 0)

/* OPHYPWR */
#define PHY_0_SLEEP                     (0x1 << 5)
#define OTG_DISABLE_0                   (0x1 << 4)
#define ANALOG_PWRDOWN                  (0x1 << 3)
#define FORCE_SUSPEND_0                 (0x1 << 0)

/* URSTCON */
#define HOST_SW_RST                     (0x1 << 4)
#define PHY_SW_RST1                     (0x1 << 3)
#define PHYLNK_SW_RST                   (0x1 << 2)
#define LINK_SW_RST                     (0x1 << 1)
#define PHY_SW_RST0                     (0x1 << 0)

/* OPHYCLK */
#define COMMON_ON_N1                    (0x1 << 7)
#define COMMON_ON_N0                    (0x1 << 4)
#define ID_PULLUP0                      (0x1 << 2)
#define CLK_SEL_24MHZ                   (0x3 << 0)
#define CLK_SEL_12MHZ                   (0x2 << 0)
#define CLK_SEL_48MHZ                   (0x0 << 0)

#define EXYNOS4X12_ID_PULLUP0		(0x01 << 3)
#define EXYNOS4X12_COMMON_ON_N0	(0x01 << 4)
#define EXYNOS4X12_CLK_SEL_12MHZ	(0x02 << 0)
#define EXYNOS4X12_CLK_SEL_24MHZ	(0x05 << 0)

/* Device Configuration Register DCFG */
#define DEV_SPEED_HIGH_SPEED_20         (0x0 << 0)
#define DEV_SPEED_FULL_SPEED_20         (0x1 << 0)
#define DEV_SPEED_LOW_SPEED_11          (0x2 << 0)
#define DEV_SPEED_FULL_SPEED_11         (0x3 << 0)
#define EP_MISS_CNT(x)                  (x << 18)
#define DEVICE_ADDRESS(x)               (x << 4)
#define DESC_DMA			(1 << 23)

/* Core Reset Register (GRSTCTL) */
#define TX_FIFO_FLUSH                   (0x1 << 5)
#define RX_FIFO_FLUSH                   (0x1 << 4)
#define TX_FIFO_NUMBER(x)               (x << 6)
#define TX_FIFO_FLUSH_ALL               TX_FIFO_NUMBER(0x10)
#define AHBIDLE				(0x1 << 31)

/* Masks definitions */
#define GINTMSK_INIT	(INT_OUT_EP | INT_IN_EP | INT_RESUME | INT_ENUMDONE\
			| INT_RESET | INT_SUSPEND)
#define DOEPMSK_INIT	(CTRL_OUT_EP_SETUP_PHASE_DONE | AHB_ERROR|TRANSFER_DONE)
#define DIEPMSK_INIT	(NON_ISO_IN_EP_TIMEOUT|AHB_ERROR|TRANSFER_DONE)
#define GAHBCFG_INIT	(PTXFE_HALF | NPTXFE_HALF | MODE_DMA | BURST_INCR4\
			| GBL_INT_UNMASK)

/* Device Endpoint X Transfer Size Register (DIEPTSIZX) */
#define DIEPT_SIZ_PKT_CNT(x)                      (x << 19)
#define DIEPT_SIZ_XFER_SIZE(x)                    (x << 0)

/* Device OUT Endpoint X Transfer Size Register (DOEPTSIZX) */
#define DOEPT_SIZ_PKT_CNT(x)                      (x << 19)
#define DOEPT_SIZ_XFER_SIZE(x)                    (x << 0)
#define DOEPT_SIZ_XFER_SIZE_MAX_EP0               (0x7F << 0)
#define DOEPT_SIZ_XFER_SIZE_MAX_EP                (0x7FFF << 0)
#define DOEPT_SIZ_SUS_CNT(x)                      (x << 29)

/* Device Endpoint-N Control Register (DIEPCTLn/DOEPCTLn) */
#define DIEPCTL_TX_FIFO_NUM(x)                    (x << 22)
#define DIEPCTL_TX_FIFO_NUM_MASK                  (~DIEPCTL_TX_FIFO_NUM(0xF))

/* Device ALL Endpoints Interrupt Register (DAINT) */
#define DAINT_IN_EP_INT(x)                        (x << 0)
#define DAINT_OUT_EP_INT(x)                       (x << 16)

#define PCGCTL_GATEHCLK                 (1 << 1)
#define PCGCTL_STOPPCLK                 (1 << 0)
/*===================================================================== */
/*definitions related to DMA descriptor */
#define DESC_BS_MASK			(0x3 << 30)
#define DESC_BS_HOST_RDY		(0x0 << 30)
#define DESC_BS_DMA_BUSY		(0x1 << 30)
#define DESC_BS_DMA_DONE		(0x2 << 30)
#define DESC_BS_HOST_BUSY		(0x3 << 30)
#define DESC_LAST			(0x1 << 27)
#define DESC_SP				(0x1 << 26)
#define DESC_IOC			(0x1 << 25)
#define DESC_ISO_FRM_NUM_MASK		(0x7FF << 12)
#define DESC_ISO_FRM_NUM_SHIFT		(12)
#define DESC_SIZE_MASK			(0xFFFF << 0)
/* out transfer. */
#define DESC_RXSTS_MASK			(0x3 << 28)
#define DESC_RXSTS_NO_ERR		(0x0 << 28)
#define DESC_RXSTS_BUF_ERR		(0x3 << 28)
/* varies on non-isochronous out*/
#define DESC_SR				(0x1 << 24)
#define DESC_MTRF			(0x1 << 23)
#define DESC_NAK			(0x1 << 16)
/* varies on isochronous out*/
#define DESC_ISO_OUT_PID_MASK		(0x3 << 23)
#define DESC_ISO_OUT_PID_DATA0		(0x0 << 23)
#define DESC_ISO_OUT_PID_DATA1		(0x1 << 23)
#define DESC_ISO_OUT_PID_DATA2		(0x2 << 23)
#define DESC_ISO_OUT_PID_MDATA		(0x3 << 23)
#define DESC_ISO_OUT_SIZE_MASK		(0x7FF << 0)
/* in transfer*/
#define DESC_TXSTS_MASK			(0x3 << 28)
#define DESC_TXSTS_NO_ERR		(0x0 << 28)
#define DESC_TXSTS_BUFFFLUSH		(0x1 << 28)
#define DESC_TXSTS_BUF_ERR		(0x3 << 28)
/* varies on isochronous in*/
#define DESC_ISO_IN_PID_MASK		(0x3 << 23)
#define DESC_ISO_IN_PID_DATA0		(0x1 << 23)
#define DESC_ISO_IN_PID_DATA1		(0x2 << 23)
#define DESC_ISO_IN_PID_MDAT2		(0x3 << 23)
#define DESC_ISO_IN_SIZE_MASK		(0xFFF << 0)
#endif
