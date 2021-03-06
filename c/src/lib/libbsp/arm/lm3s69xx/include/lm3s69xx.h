/**
 * @file
 *
 * @ingroup lm3s69xx_reg
 *
 * @brief Register definitions.
 */

/*
 * Copyright � 2013 Eugeniy Meshcheryakov <eugen@debian.org>
 *
 * Copyright (c) 2011 Sebastian Huber.  All rights reserved.
 *
 *  embedded brains GmbH
 *  Obere Lagerstr. 30
 *  82178 Puchheim
 *  Germany
 *  <rtems@embedded-brains.de>
 *
 * The license and distribution terms for this file may be
 * found in the file LICENSE in this distribution or at
 * http://www.rtems.org/license/LICENSE.
 */

#ifndef LIBBSP_ARM_LM3S69XX_LM3S69XX_H
#define LIBBSP_ARM_LM3S69XX_LM3S69XX_H
#include <bspopts.h>
#include <bsp/utility.h>

/**
 * @defgroup lm3s69xx_reg Register Definitions
 *
 * @ingroup arm_lm3s69xx
 *
 * @brief Register Definitions 
 */

#define LM3S69XX_SYSCON_BASE 0x400fe000

#define LM3S69XX_PWM_0_BASE 0x40028000

#define LM3S69XX_UART_0_BASE 0x4000c000
#define LM3S69XX_UART_1_BASE 0x4000d000
#define LM3S69XX_UART_2_BASE 0x4000e000
#define LM3S69XX_UART_3_BASE 0x4000f000
#define LM3S69XX_UART_4_BASE 0x40010000
#define LM3S69XX_UART_5_BASE 0x40011000
#define LM3S69XX_UART_6_BASE 0x40012000
#define LM3S69XX_UART_7_BASE 0x40013000

#ifdef LM3S69XX_USE_AHB_FOR_GPIO
#define LM3S69XX_GPIO_A_BASE 0x40058000
#define LM3S69XX_GPIO_B_BASE 0x40059000
#define LM3S69XX_GPIO_C_BASE 0x4005a000
#define LM3S69XX_GPIO_D_BASE 0x4005b000
#define LM3S69XX_GPIO_E_BASE 0x4005c000
#define LM3S69XX_GPIO_F_BASE 0x4005d000
#if LM3S69XX_NUM_GPIO_BLOCKS > 6
#define LM3S69XX_GPIO_G_BASE 0x4005e000
#if LM3S69XX_NUM_GPIO_BLOCKS > 7
#define LM3S69XX_GPIO_H_BASE 0x4005f000
#if LM3S69XX_NUM_GPIO_BLOCKS > 8
#define LM3S69XX_GPIO_J_BASE 0x40060000
#define LM3S69XX_GPIO_K_BASE 0x40061000
#define LM3S69XX_GPIO_L_BASE 0x40062000
#define LM3S69XX_GPIO_M_BASE 0x40063000
#define LM3S69XX_GPIO_N_BASE 0x40064000
#define LM3S69XX_GPIO_P_BASE 0x40065000
#define LM3S69XX_GPIO_Q_BASE 0x40066000
#endif
#endif
#endif

#define LM3S69XX_GPIO(port) ((volatile lm3s69xx_gpio *)(LM3S69XX_GPIO_A_BASE + (port) * 0x1000))
#else /* LM3S69XX_USE_AHB_FOR_GPIO */
#define LM3S69XX_GPIO_A_BASE 0x40004000
#define LM3S69XX_GPIO_B_BASE 0x40005000
#define LM3S69XX_GPIO_C_BASE 0x40006000
#define LM3S69XX_GPIO_D_BASE 0x40007000
#define LM3S69XX_GPIO_E_BASE 0x40024000
#define LM3S69XX_GPIO_F_BASE 0x40025000
#if LM3S69XX_NUM_GPIO_BLOCKS > 6
#define LM3S69XX_GPIO_G_BASE 0x40026000
#if LM3S69XX_NUM_GPIO_BLOCKS > 7
#define LM3S69XX_GPIO_H_BASE 0x40027000
#if LM3S69XX_NUM_GPIO_BLOCKS > 8
#define LM3S69XX_GPIO_J_BASE 0x4003D000
#endif
#endif
#endif

#define LM3S69XX_GPIO(port) ((volatile lm3s69xx_gpio *)(((port) < 4) ? \
           (LM3S69XX_GPIO_A_BASE + (port) * 0x1000) : \
           (LM3S69XX_GPIO_E_BASE + ((port) - 4) * 0x1000)))
#endif /* LM3S69XX_USE_AHB_FOR_GPIO */

#define LM3S69XX_SSI_0_BASE 0x40008000
#if LM3S69XX_NUM_SSI_BLOCKS > 1
#define LM3S69XX_SSI_1_BASE 0x40009000
#if LM3S69XX_NUM_SSI_BLOCKS > 2
#define LM3S69XX_SSI_2_BASE 0x4000A000
#if LM3S69XX_NUM_SSI_BLOCKS > 3
#define LM3S69XX_SSI_3_BASE 0x4000B000
#endif
#endif
#endif

#define LM3S69XX_SYSCON ((volatile lm3s69xx_syscon *)LM3S69XX_SYSCON_BASE)

#define LM3S69XX_PWM_0 ((volatile lm3s69xx_pwm *)(LM3S69XX_PWM_0_BASE))

#define LM3S69XX_PLL_FREQUENCY 480000000U

typedef struct  {
  uint32_t data[256]; /* Masked data registers are included here. */
  uint32_t dir;
  uint32_t is;
  uint32_t ibe;
  uint32_t iev;
  uint32_t im;
  uint32_t ris;
  uint32_t mis;
  uint32_t icr;
  uint32_t afsel;
  uint32_t reserved_0[55];
  uint32_t dr2r;
  uint32_t dr4r;
  uint32_t dr8r;
  uint32_t odr;
  uint32_t pur;
  uint32_t pdr;
  uint32_t slr;
  uint32_t den;
  uint32_t lock;
  uint32_t cr;
  uint32_t amsel;
  uint32_t pctl;
  uint32_t adcctl;
  uint32_t damctl;
  uint32_t si;
  uint32_t dr12r;
  uint32_t wakepen;
  uint32_t wakelvl;
  uint32_t wakestat;

  uint32_t reserved_1[669];
 
  uint32_t pp;
  uint32_t pc;
} lm3s69xx_gpio;

typedef struct {
  uint32_t did0;
  uint32_t did1;

uint32_t reserved_0[12];

#define SYSCONPBORCTL_BORIOR BSP_BIT32(1)
  uint32_t pborctl;

  uint32_t reserved_1[5];

#define SYSCONRIS_MOSCPUPRIS BSP_BIT32(8)
#define SYSCONRIS_USBPLLRIS BSP_BIT32(7)
#define SYSCONRIS_PLLLRIS BSP_BIT32(6)
#define SYSCONRIS_BORRIS BSP_BIT32(1)
  uint32_t ris;

#define SYSCONIMC_MOSCPUPIM BSP_BIT32(8)
#define SYSCONIMC_USBPLLLIM BSP_BIT32(7)
#define SYSCONIMC_PLLLIM BSP_BIT32(6)
#define SYSCONIMC_BORIM BSP_BIT32(1)
  uint32_t imc;

#define SYSCONMISC_MOSCPUPMIS BSP_BIT32(8)
#define SYSCONMISC_USBPLLLMIS BSP_BIT32(7)
#define SYSCONMISC_PLLLMIS BSP_BIT32(6)
#define SYSCONMISC_BORMIS BSP_BIT32(1)
  uint32_t misc;

#define SYSCONRESC_MOSCFAIL BSP_BIT32(16)
#define SYSCONRESC_SW BSP_BIT32(4)
#define SYSCONRESC_WDT BSP_BIT32(3)
#define SYSCONRESC_BOR BSP_BIT32(2)
#define SYSCONRESC_POR BSP_BIT32(1)
#define SYSCONRESC_EXT BSP_BIT32(0)
  uint32_t resc;

#define SYSCONPWRTC_VDDA_UBOR BSP_BIT32(4)
#define SYSCONPWRTC_VDD_UBOR BSP_BIT32(0)
  uint32_t pwrtc;
  uint32_t nmic;
  uint32_t reserved_2[5];

#define SYSCONMOSCCTL_OSCRNG BSP_BIT32(4)
#define SYSCONMOSCCTL_PWRDN BSP_BIT32(3)
#define SYSCONMOSCCTL_NOXTAL BSP_BIT32(2)
#define SYSCONMOSCCTL_MOSCIM BSP_BIT32(1)
#define SYSCONMOSCCTL_CVAL BSP_BIT32(0)
  uint32_t moscctl;

  uint32_t reserved_3[12];

#define SYSCONRSCLKCFG_MEMTIMU BSP_BIT32(31)
#define SYSCONRSCLKCFG_NEWFREQ BSP_BIT32(30)
#define SYSCONRSCLKCFG_ACG BSP_BIT32(29)
#define SYSCONRSCLKCFG_USEPLL BSP_BIT32(28)
#define SYSCONRSCLKCFG_PLLSRC(val) BSP_FLD32(val, 24, 27)
#define SYSCONRSCLKCFG_PLLSRC_MSK BSP_MSK32(24, 27)
#define SYSCONRSCLKCFG_OSCSRC(val) BSP_FLD32(val, 20, 23)
#define SYSCONRSCLKCFG_OSCSRC_MSK BSP_MSK32(20, 23)
#define SYSCONRSCLKCFG_OSYSDIV(val) BSP_FLD32(val, 10, 19)
#define SYSCONRSCLKCFG_OSYSDIV_MSK BSP_MSK32(10, 19)
#define SYSCONRSCLKCFG_PSYSDIV(val) BSP_FLD32(val, 0, 9)
#define SYSCONRSCLKCFG_PSYSDIV_MSK BSP_MSK32(0, 9)

  uint32_t rsclkcfg;
  uint32_t reserved_4[3];


#define SYSCONMEMTIM0_EBCHT(val) BSP_FLD32(val, 22, 25)
#define SYSCONMEMTIM0_EBCHT_MSK BSP_MSK32(22, 25)
#define SYSCONMEMTIM0_EBCE BSP_BIT32(21)
#define SYSCONMEMTIM0_EWS(val) BSP_FLD32(val, 16, 19)
#define SYSCONMEMTIM0_EWS_MSK BSP_MSK32(16, 19)
#define SYSCONMEMTIM0_FBCHT(val) BSP_FLD32(val, 6, 9)
#define SYSCONMEMTIM0_FBCHT_MSK BSP_MSK32(6, 9)
#define SYSCONMEMTIM0_FBCE BSP_BIT32(5)
#define SYSCONMEMTIM0_FWS(val) BSP_FLD32(val, 0, 3)
#define SYSCONMEMTIM0_FWS_MSK BSP_MSK32(0, 3)

  uint32_t memtim0;

  uint32_t reserved_5[29];

  
  uint32_t altclkcfg;

  uint32_t reserved_7[2];


#define SYSCONDSCLKCFG_PIOSCPD BSP_BIT32(31)
#define SYSCONDSCLKCFG_MOSCDPD BSP_BIT32(30)
#define SYSCONDSCLKCFG_DSOSCSRC(val) BSP_FLD32(val, 20, 23)
#define SYSCONDSCLKCFG_DSOSCSRC_MSK BSP_MSK32(20, 23)
#define SYSCONDSCLKCFG_DSSYSDIV(val) BSP_FLD32(val, 0, 9)
#define SYSCONDSCLKCFG_DSSYSDIV_MSK BSP_MSK32(0, 9)

  uint32_t dsclkcfg;
  uint32_t divsclk;
  uint32_t sysprop;
  uint32_t piosccal;
  uint32_t pioscstat;

  uint32_t reserved_8[2];

#define SYSCONPLLFREQ0_PLLPWR BSP_BIT32(23)
#define SYSCONPLLFREQ0_MFRAC(val) BSP_FLD32(val, 10, 19)
#define SYSCONPLLFREQ0_MFRAC_MSK BSP_MSK32(10, 19)
#define SYSCONPLLFREQ0_MINT(val) BSP_FLD32(val, 0, 9)
#define SYSCONPLLFREQ0_MINT_MSK BSP_MSK32(0, 9)

  uint32_t pllfreq0;

#define SYSCONPLLFREQ1_Q(val) BSP_FLD32(val, 8, 12)
#define SYSCONPLLFREQ1_Q_MSK BSP_MSK32(8, 12)
#define SYSCONPLLFREQ1_N(val) BSP_FLD32(val, 0, 4)
#define SYSCONPLLFREQ1_N_MSK BSP_MSK32(0, 4)

  uint32_t pllfreq1;

#define SYSCONPLLSTAT_LOCK BSP_BIT32(0)

  uint32_t pllstat;

  uint32_t reserved_9[7];

  uint32_t slppwrcfg;
  uint32_t dslppwrcfg;
  
  uint32_t reserved_10[4];
  
  uint32_t nvmstat;
  
  uint32_t reserved_11[4];

  uint32_t ldospctl;
  uint32_t ldospcal;
  uint32_t ldodpctl;
  uint32_t ldodpcal;
  uint32_t reserved_12[2];
  uint32_t sdpmst;
  uint32_t reserved_13[2];
  uint32_t resbehavctl;
  uint32_t reserved_14[6];
  uint32_t hssr;

  uint32_t reserved_15[34];

  uint32_t usbpds;
  uint32_t usbmpc;
  uint32_t emacpds;
  uint32_t emacmpc;

  uint32_t reserved_16[2];

  uint32_t can0pds;
  uint32_t can0mpc;
  uint32_t can1pds;
  uint32_t can1mpc;

  uint32_t reserved_17[22];

  uint32_t ppwd;
  uint32_t pptimer;
  uint32_t ppgpio;
  uint32_t ppdma;
  uint32_t ppepi;
  uint32_t pphib;
  uint32_t ppuart;
  uint32_t ppssi;
  uint32_t ppi2c;

  uint32_t reserved_18;

  uint32_t ppusb;

  uint32_t reserved_19;

  uint32_t ppephy;
  uint32_t ppcan;
  uint32_t ppadc;
  uint32_t ppacmp;
  uint32_t pppwm;
  uint32_t ppqei;
  uint32_t pplpc;

  uint32_t reserved_20;

  uint32_t pppeci;
  uint32_t ppfan;
  uint32_t ppeeprom;
  uint32_t ppwtimer;

  uint32_t reserved_21[4];

  uint32_t pprts;
  uint32_t ppccm;

  uint32_t reserved_22[6];

  uint32_t pplcd;

  uint32_t reserved_23;

  uint32_t ppowire;
  uint32_t ppemac;
  uint32_t ppprb;
  uint32_t pphim;

  uint32_t reserved_24[86];

  uint32_t srwd;
  uint32_t srtimer;
  uint32_t srgpio;
  uint32_t srdma;
  uint32_t srepi;
  uint32_t srhib;
  uint32_t sruart;
  uint32_t srssi;
  uint32_t sri2c;
  
  uint32_t reserved_25;

  uint32_t srusb;
  uint32_t reserved_6;
  uint32_t srephy;
  uint32_t srcan;
  uint32_t sradc;
  uint32_t sracmp;
  uint32_t srpwm;
  uint32_t srqei;

  uint32_t reserved_26[4];

  uint32_t sreeprom;

  uint32_t reserved_27[6];

  uint32_t srccm;

  uint32_t reserved_28[9];

  uint32_t sremac;

  uint32_t reserved_58[24];
#define SYSCONRCGCWD_R1 BSP_BIT32(1)
#define SYSCONRCGCWD_R0 BSP_BIT32(0)
  uint32_t rcgcwd;

#define SYSCONRCGCTIMER_R7 BSP_BIT32(7)
#define SYSCONRCGCTIMER_R6 BSP_BIT32(6)
#define SYSCONRCGCTIMER_R5 BSP_BIT32(5)
#define SYSCONRCGCTIMER_R4 BSP_BIT32(4)
#define SYSCONRCGCTIMER_R3 BSP_BIT32(3)
#define SYSCONRCGCTIMER_R2 BSP_BIT32(2)
#define SYSCONRCGCTIMER_R1 BSP_BIT32(1)
#define SYSCONRCGCTIMER_R0 BSP_BIT32(0)
  uint32_t rcgctimer;


#define SYSCONRCGCGPIO_R14 BSP_BIT32(14)
#define SYSCONRCGCGPIO_R13 BSP_BIT32(13)
#define SYSCONRCGCGPIO_R12 BSP_BIT32(12)
#define SYSCONRCGCGPIO_R11 BSP_BIT32(11)
#define SYSCONRCGCGPIO_R10 BSP_BIT32(10)
#define SYSCONRCGCGPIO_R9 BSP_BIT32(9)
#define SYSCONRCGCGPIO_R8 BSP_BIT32(8)
#define SYSCONRCGCGPIO_R7 BSP_BIT32(7)
#define SYSCONRCGCGPIO_R6 BSP_BIT32(6)
#define SYSCONRCGCGPIO_R5 BSP_BIT32(5)
#define SYSCONRCGCGPIO_R4 BSP_BIT32(4)
#define SYSCONRCGCGPIO_R3 BSP_BIT32(3)
#define SYSCONRCGCGPIO_R2 BSP_BIT32(2)
#define SYSCONRCGCGPIO_R1 BSP_BIT32(1)
#define SYSCONRCGCGPIO_R0 BSP_BIT32(0)
  uint32_t rcgcgpio;

#define SYSCONRCGCDMA_R0 BSP_BIT32(0)
  uint32_t rcgcdma;

#define SYSCONRCGCEPI_R0 BSP_BIT32(0)
  uint32_t rcgcepi;


#define SYSCONRCGCHIB_R0 BSP_BIT32(0)
  uint32_t rcgchib;


#define SYSCONRCGCUART_R7 BSP_BIT32(7)
#define SYSCONRCGCUART_R6 BSP_BIT32(6)
#define SYSCONRCGCUART_R5 BSP_BIT32(5)
#define SYSCONRCGCUART_R4 BSP_BIT32(4)
#define SYSCONRCGCUART_R3 BSP_BIT32(3)
#define SYSCONRCGCUART_R2 BSP_BIT32(2)
#define SYSCONRCGCUART_R1 BSP_BIT32(1)
#define SYSCONRCGCUART_R0 BSP_BIT32(0)
  uint32_t rcgcuart;

#define SYSCONRCGCSSI_R3 BSP_BIT32(3)
#define SYSCONRCGCSSI_R2 BSP_BIT32(2)
#define SYSCONRCGCSSI_R1 BSP_BIT32(1)
#define SYSCONRCGCSSI_R0 BSP_BIT32(0)
  uint32_t rcgcssi;

#define SYSCONRCGCI2C_R9 BSP_BIT32(9)
#define SYSCONRCGCI2C_R8 BSP_BIT32(8)
#define SYSCONRCGCI2C_R7 BSP_BIT32(7)
#define SYSCONRCGCI2C_R6 BSP_BIT32(6)
#define SYSCONRCGCI2C_R5 BSP_BIT32(5)
#define SYSCONRCGCI2C_R4 BSP_BIT32(4)
#define SYSCONRCGCI2C_R3 BSP_BIT32(3)
#define SYSCONRCGCI2C_R2 BSP_BIT32(2)
#define SYSCONRCGCI2C_R1 BSP_BIT32(1)
#define SYSCONRCGCI2C_R0 BSP_BIT32(0)
  uint32_t rcgci2c;

  uint32_t reserved_29;

#define SYSCONRCGCUSB_R0 BSP_BIT32(0)
  uint32_t rcgcusb;

#define SYSCONRCGCEPHY_R0 BSP_BIT32(0)
  uint32_t rcgcephy;

#define SYSCONRCGCCAN_R1 BSP_BIT32(1)
#define SYSCONRCGCCAN_R0 BSP_BIT32(0)
  uint32_t rcgccan;

#define SYSCONRCGCADC_R1 BSP_BIT32(1)
#define SYSCONRCGCADC_R0 BSP_BIT32(0)
  uint32_t rcgcadc;

#define SYSCONRCGCACMP_R0 BSP_BIT32(0)
  uint32_t rcgcacmp;

#define SYSCONRCGCPWM_R0 BSP_BIT32(0)
  uint32_t rcgcpwm;

#define SYSCONRCGCQEI_R0 BSP_BIT32(0)
  uint32_t rcgcqei;

  uint32_t reserved_30[4];

#define SYSCONRCGCEEPROM_R0 BSP_BIT32(0)
  uint32_t rcgceeprom;

  uint32_t reserved_31[6];

#define SYSCONRCGCCCM_R0 BSP_BIT32(0)
  uint32_t rcgcccm;

  uint32_t reserved_32[9];

#define SYSCONRCGCMAC_R0 BSP_BIT32(0)
  uint32_t rcgcemac;

  uint32_t reserved_33[24];

  uint32_t scgcwd;
  uint32_t scgctimer;
  uint32_t scgcgpio;
  uint32_t scgcdma;
  uint32_t scgcepi;
  uint32_t scgchib;
  uint32_t scgcuart;
  uint32_t scgcssi;
  uint32_t scgci2c;

  uint32_t reserved_34;

  uint32_t scgcusb;

  uint32_t reserved_35;

  uint32_t scgcephy;
  uint32_t scgccan;
  uint32_t scgcadc;
  uint32_t scgcacmp;
  uint32_t scgcpwm;
  uint32_t scgcqei;

  uint32_t reserved_36[4];

  uint32_t scgceeprom;

  uint32_t reserved_37[6];

  uint32_t scgcccm;

  uint32_t reserved_38[9];

  uint32_t scgcemac;

  uint32_t reserved_39[24];

  uint32_t dcgcwd;
  uint32_t dcgctimer;
  uint32_t dcgcgpio;
  uint32_t dcgcdma;
  uint32_t dcgcepi;
  uint32_t dcgchib;
  uint32_t dcgcuart;
  uint32_t dcgcssi;
  uint32_t dcgci2c;

  uint32_t reserved_40;

  uint32_t dcgcusb;

  uint32_t reserved_41;

  uint32_t dcgcephy;
  uint32_t dcgccan;
  uint32_t dcgcadc;
  uint32_t dcgcacmp;
  uint32_t dcgcpwm;
  uint32_t dcgcqei;

  uint32_t reserved_42[4];

  uint32_t dcgceeprom;

  uint32_t reserved_43[6];

  uint32_t dcgcccm;

  uint32_t reserved_44[9];

  uint32_t dcgcemac;

  uint32_t reserved_45[24];

  uint32_t pcwd;
  uint32_t pctimer;
  uint32_t pcgpio;
  uint32_t pcdma;
  uint32_t pcepi;
  uint32_t pchib;
  uint32_t pcuart;
  uint32_t pcssi;
  uint32_t pci2c;

  uint32_t reserved_46;

  uint32_t pcusb;

  uint32_t reserved_47;

  uint32_t pcephy;
  uint32_t pccan;
  uint32_t pcadc;
  uint32_t pcacmp;
  uint32_t pcpwm;
  uint32_t pcqei;

  uint32_t reserved_48[4];

  uint32_t pceeprom;

  uint32_t reserved_49[6];

  uint32_t pcccm;

  uint32_t reserved_50[9];

  uint32_t pcemac;

  uint32_t reserved_51[24];

  uint32_t prwd;
  uint32_t prtimer;
  uint32_t prgpio;
  uint32_t prdma;
  uint32_t prepi;
  uint32_t prhib;
  uint32_t pruart;
  uint32_t prssi;
  uint32_t pri2c;

  uint32_t reserved_52;

  uint32_t prusb;

  uint32_t reserved_53;

  uint32_t prephy;
  uint32_t prcan;
  uint32_t pradc;
  uint32_t pracmp;
  uint32_t prpwm;
  uint32_t prqei;

  uint32_t reserved_54[4];

  uint32_t preeprom;

  uint32_t reserved_55[6];

  uint32_t prccm;

  uint32_t reserved_56[9];

  uint32_t premac;

  uint32_t reserved_57[288];

  uint32_t uniqueid0;

  uint32_t uniqueid1;

  uint32_t uniqueid2;

  uint32_t uniqueid3;                               

} lm3s69xx_syscon;

typedef struct {
#define UARTDR_OE BSP_BIT32(11)
#define UARTDR_BE BSP_BIT32(10)
#define UARTDR_PE BSP_BIT32(9)
#define UARTDR_FE BSP_BIT32(8)
#define UARTDR_ERROR_MSK BSP_MSK32(8, 11)
#define UARTDR_DATA(val) BSP_FLD32(val, 0, 7)
#define UARTDR_DATA_GET(reg) BSP_FLD32GET(reg, 0, 7)
  uint32_t dr;

  uint32_t rsr_ecr;
  uint32_t reserved_0[4];
#define UARTFR_RI BSP_BIT32(8)
#define UARTFR_TXFE BSP_BIT32(7)
#define UARTFR_RXFF BSP_BIT32(6)
#define UARTFR_TXFF BSP_BIT32(5)
#define UARTFR_RXFE BSP_BIT32(4)
#define UARTFR_BUSY BSP_BIT32(3)
#define UARTFR_DCD BSP_BIT32(2)
#define UARTFR_DSR BSP_BIT32(1)
#define UARTFR_CTS BSP_BIT32(0)
  uint32_t fr;

  uint32_t reserved_1;

  uint32_t ilpr;
  uint32_t ibrd;
  uint32_t fbrd;

#define UARTLCRH_SPS BSP_BIT32(7)
#define UARTLCRH_WLEN(val) BSP_FLD32(val, 5, 6)
#define UARTLCRH_FEN BSP_BIT32(4)
#define UARTLCRH_STP2 BSP_BIT32(3)
#define UARTLCRH_EPS BSP_BIT32(2)
#define UARTLCRH_PEN BSP_BIT32(1)
#define UARTLCRH_BRK BSP_BIT32(0)
  uint32_t lcrh;

#define UARTCTL_RXE BSP_BIT32(9)
#define UARTCTL_TXE BSP_BIT32(8)
#define UARTCTL_LBE BSP_BIT32(7)
#define UARTCTL_SIRLP BSP_BIT32(2)
#define UARTCTL_SIREN BSP_BIT32(1)
#define UARTCTL_UARTEN BSP_BIT32(0)
  uint32_t ctl;

#define UARTIFLS_RXIFLSEL(val) BSP_FLD32(val, 3, 5)
#define UARTIFLS_TXIFLSEL(val) BSP_FLD32(val, 0, 2)
  uint32_t ifls;

#define UARTI_OE BSP_BIT32(10)
#define UARTI_BE BSP_BIT32(9)
#define UARTI_PE BSP_BIT32(8)
#define UARTI_FE BSP_BIT32(7)
#define UARTI_RT BSP_BIT32(6)
#define UARTI_TX BSP_BIT32(5)
#define UARTI_RX BSP_BIT32(4)
  uint32_t im;
  uint32_t ris;
  uint32_t mis;
  uint32_t icr;
#if LM3S69XX_HAS_UDMA
  uint32_t dmactl;
#endif
  uint32_t reserved_2[22];
  uint32_t bitaddr;
  uint32_t bitamask;
  uint32_t reserved_3[965];
  uint32_t pp;
  uint32_t reserved_4;

#define UARTCC_CS(val) BSP_FLD32(val, 0, 3)
  uint32_t cc;
} lm3s69xx_uart;

typedef struct {
#define SSICR0_SCR(val) BSP_FLD32(val, 8, 15)
#define SSICR0_SPH BSP_BIT32(7)
#define SSICR0_SPO BSP_BIT32(6)
#define SSICR0_FRF(val) BSP_FLD32(val, 4, 5)
#define SSICR0_DSS(val) BSP_FLD32(val, 0, 3)
  uint32_t cr0;

#define SSICR1_SOD BSP_BIT32(3)
#define SSICR1_MS BSP_BIT32(2)
#define SSICR1_SSE BSP_BIT32(1)
#define SSICR1_LBM BSP_BIT32(0)
  uint32_t cr1;
  uint32_t dr;

#define SSISR_BSY BSP_BIT32(4)
#define SSISR_RFF BSP_BIT32(3)
#define SSISR_RNE BSP_BIT32(2)
#define SSISR_TNF BSP_BIT32(1)
#define SSISR_TFE BSP_BIT32(0)
  uint32_t sr;

#define SSI_CPSRDIV(val) BSP_FLD32(val, 0, 7)
  uint32_t cpsr;

#define SSII_TX BSP_BIT32(3)
#define SSII_RX BSP_BIT32(2)
#define SSII_RT BSP_BIT32(1)
#define SSII_ROR BSP_BIT32(0)
  uint32_t im;
  uint32_t ris;
  uint32_t mis;
  uint32_t icr;

#if LM3S69XX_HAS_UDMA
#define SSIDMACTL_TXDMAE BSP_BIT32(1)
#define SSIDMACTL_RXDMAE BSP_BIT32(0)
  uint32_t dmactl;
#endif /* LM3S69XX_HAS_UDMA */
  uint32_t reserved_0[998];
  uint32_t pp;
  uint32_t reserved_1;
  uint32_t cc;
} lm3s69xx_ssi;

typedef struct  {
 uint32_t ctl;
 uint32_t sync;
 uint32_t enable;
 uint32_t invert;
 uint32_t fault;
 uint32_t inten;
 uint32_t ris;
 uint32_t isc;
 uint32_t status;
 uint32_t faultval;
 uint32_t enupd;

 uint32_t reserved_0[997];
 uint32_t pp;
 uint32_t reserved_1;

#define PWMCC_USEPWM BSP_BIT32(8)
#define PWMCC_PWMDIV(val) BSP_FLD32(val, 0, 2)
#define PWMCC_PWMDIV_DIV2_VAL 0
#define PWMCC_PWMDIV_DIV4_VAL 1
#define PWMCC_PWMDIV_DIV8_VAL 2
#define PWMCC_PWMDIV_DIV16_VAL 3
#define PWMCC_PWMDIV_DIV32_VAL 4
#define PWMCC_PWMDIV_DIV64_VAL 5
#define PWMCC_PWMDIV_MSK BSP_MSK32(0, 2)
 uint32_t cc;

} lm3s69xx_pwm;

#endif /* LIBBSP_ARM_LM3S69XX_LM3S69XX_H */
