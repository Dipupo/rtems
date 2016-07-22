/*
 *  This routine does the bulk of the system initialization.
 */

/*
 * Copyright © 2013 Eugeniy Meshcheryakov <eugen@debian.org>
 *
 * The license and distribution terms for this file may be
 * found in the file LICENSE in this distribution or at
 * http://www.rtems.org/license/LICENSE.
 */

#include <bsp.h>
#include <bspopts.h>
#include <bsp/bootcard.h>
#include <bsp/irq-generic.h>
#include <bsp/lm3s69xx.h>
#include <bsp/io.h>
#include <bsp/syscon.h>
#include <assert.h>

static void init_main_osc(void)
{
  volatile lm3s69xx_syscon *syscon = LM3S69XX_SYSCON;

  uint32_t pllfreq0 = syscon->pllfreq0;
  uint32_t pllfreq1 = syscon->pllfreq1;
  uint32_t memtim0 = syscon->memtim0;
  uint32_t pllstat = syscon->pllstat;
  uint32_t moscctl = syscon->moscctl;
  uint32_t rsclkcfg = syscon->rsclkcfg;
  uint32_t ris = syscon->ris;
  uint32_t dsclkcfg = syscon->dsclkcfg;
  uint32_t pwrtc = syscon->pwrtc;


  moscctl = (moscctl & ~(SYSCONMOSCCTL_NOXTAL | SYSCONMOSCCTL_PWRDN));
  syscon->moscctl = moscctl;

 while ((syscon->ris & SYSCONRIS_MOSCPUPRIS) == 0)
      /* Wait for bit to set */;


  rsclkcfg |= SYSCONRSCLKCFG_OSCSRC(0x3);
  syscon->rsclkcfg = rsclkcfg;

  dsclkcfg |= SYSCONDSCLKCFG_DSOSCSRC(0x3);
  syscon->dsclkcfg = dsclkcfg;

  pllfreq0 &= ~(SYSCONPLLFREQ0_MINT(0xFFFF));
  pllfreq0 &= ~(SYSCONPLLFREQ0_MFRAC(0xFFFF));
  pllfreq0 |= (SYSCONPLLFREQ0_MINT(0x60));
  pllfreq0 |= (SYSCONPLLFREQ0_MFRAC(0x0));

  syscon->pllfreq0 = pllfreq0;

  pllfreq1 &= ~(SYSCONPLLFREQ1_N(0xFFFF));
  pllfreq1 &= ~(SYSCONPLLFREQ1_Q(0xFFFF));

  pllfreq1 |= (SYSCONPLLFREQ1_N (0x4));
  pllfreq1 |= (SYSCONPLLFREQ1_Q (0x0));

  syscon->pllfreq1 = pllfreq1;

  pllfreq0 |= (SYSCONPLLFREQ0_PLLPWR);
  syscon->pllfreq0 = pllfreq0;

  memtim0 |= (SYSCONMEMTIM0_EWS (0x5));
  memtim0 &= ~(SYSCONMEMTIM0_EBCE);
  memtim0 |= (SYSCONMEMTIM0_EBCHT (0x6));
  memtim0 |= (SYSCONMEMTIM0_FWS (0x5));
  memtim0 &= ~(SYSCONMEMTIM0_FBCE);
  memtim0 |= (SYSCONMEMTIM0_FBCHT (0x6));

  syscon->memtim0 = memtim0;

/*  rsclkcfg |= SYSCONRSCLKCFG_NEWFREQ;

  syscon->rsclkcfg = rsclkcfg;

*/
  while ((syscon->pllstat & SYSCONPLLSTAT_LOCK) == 0)
      /* Wait for PLL lock */;

  rsclkcfg |= (SYSCONRSCLKCFG_PSYSDIV (0x3)); 
  rsclkcfg |= SYSCONRSCLKCFG_USEPLL; 
  rsclkcfg |= SYSCONRSCLKCFG_MEMTIMU; 

  syscon->rsclkcfg = rsclkcfg;

  pwrtc = (pwrtc & ~SYSCONPWRTC_VDDA_UBOR);
  pwrtc = (pwrtc & ~SYSCONPWRTC_VDD_UBOR);
  syscon->pwrtc = pwrtc;


  lm3s69xx_syscon_delay_3x_clocks(16);


 /* volatile lm3s69xx_syscon *syscon = LM3S69XX_SYSCON;

  uint32_t sysdiv_val = LM3S69XX_PLL_FREQUENCY / LM3S69XX_SYSTEM_CLOCK;
#if defined(LM3S69XX_MCU_LM3S6965) || defined(LM3S69XX_MCU_LM3S3749)
  assert(sysdiv_val * LM3S69XX_SYSTEM_CLOCK == LM3S69XX_PLL_FREQUENCY);
#endif
  assert((sysdiv_val >= 4) && (sysdiv_val <= 16));

  uint32_t rcc = syscon->rcc;
  uint32_t rcc2 = syscon->rcc2;

  rcc = (rcc & ~SYSCONRCC_USESYSDIV) | SYSCONRCC_BYPASS;
  rcc2 |= SYSCONRCC2_BYPASS2;

  syscon->rcc = rcc;
  syscon->rcc2 = rcc2;



  /*
   As per a note in Stellaris® LM4F120H5QR Microcontroller Data
   Sheet on page 219: "When transitioning the system clock
   configuration to use the MOSC as the fundamental clock source, the
   MOSCDIS bit must be set prior to reselecting the MOSC or an
   undefined system clock configuration can sporadically occur."
  

  rcc |= SYSCONRCC_MOSCDIS;
  syscon->rcc = rcc;

  rcc = (rcc & ~(SYSCONRCC_XTAL_MSK))
      | SYSCONRCC_XTAL(LM3S69XX_XTAL_CONFIG);
  rcc2 = (rcc2 & ~(SYSCONRCC2_PWRDN2 | SYSCONRCC2_OSCSRC2_MSK))
      | SYSCONRCC2_USERCC2 | SYSCONRCC2_OSCSRC2(0x0);

  /* clear PLL lock interrupt 
  syscon->misc &= (SYSCONMISC_PLLLMIS);

  syscon->rcc = rcc;
  syscon->rcc2 = rcc2;
  lm3s69xx_syscon_delay_3x_clocks(16);

  /* since now, we'll use only RCC2 as SYSCONRCC2_USERCC2 and XTAL
     (only available in RCC) are already set/

  if (sysdiv_val % 2 == 0) {
      rcc2 = (rcc2 & ~SYSCONRCC2_SYSDIV2_MSK) | SYSCONRCC2_SYSDIV2(sysdiv_val / 2 - 1);

      rcc2 &= ~(SYSCONRCC2_DIV400);
  }
  else {
      /* need to use DIV400 *
      rcc2 = (rcc2 & ~SYSCONRCC2_SYSDIV2EXT_MSK) | SYSCONRCC2_SYSDIV2EXT(sysdiv_val - 1)
          | SYSCONRCC2_DIV400;
  }
  syscon->rcc2 = rcc2;

  while ((syscon->ris & SYSCONRIS_PLLLRIS) == 0)
      /* Wait for PLL lock *;

  rcc2 &= ~(SYSCONRCC2_BYPASS2);

  syscon->rcc2 = rcc2;
  lm3s69xx_syscon_delay_3x_clocks(16);
*/
}

static const lm3s69xx_gpio_config start_config_gpio[] = {
#ifdef LM3S69XX_ENABLE_UART_0
#if defined(LM3S69XX_MCU_LM3S3749) || defined(LM3S69XX_MCU_LM3S6965) || defined(LM3S69XX_MCU_LM4F120)
  LM3S69XX_PIN_UART_RX(LM3S69XX_PORT_A, 0),
  LM3S69XX_PIN_UART_TX(LM3S69XX_PORT_A, 1),
#elif defined(LM3S69XX_MCU_TM4C129E)
  LM3S69XX_PIN_UART_RX(LM3S69XX_PORT_A, 0),
  LM3S69XX_PIN_UART_TX(LM3S69XX_PORT_A, 1),
  LM3S69XX_PIN_UART_RTS(LM3S69XX_PORT_H, 0),
  LM3S69XX_PIN_UART_RI(LM3S69XX_PORT_K, 7),
  LM3S69XX_PIN_UART_DTR(LM3S69XX_PORT_P, 2),
  LM3S69XX_PIN_UART_DSR(LM3S69XX_PORT_H, 3),
  LM3S69XX_PIN_UART_DCD(LM3S69XX_PORT_H, 2),
  LM3S69XX_PIN_UART_CTS(LM3S69XX_PORT_H, 1),
#else
#error No GPIO pin configuration for UART 0
#endif
#endif /* LM3S69XX_ENABLE_UART_0 */

#ifdef LM3S69XX_ENABLE_UART_1
#if defined(LM3S69XX_MCU_LM3S3749)
  LM3S69XX_PIN_UART_RX(LM3S69XX_PORT_B, 0),
  LM3S69XX_PIN_UART_TX(LM3S69XX_PORT_B, 1),
#elif defined(LM3S69XX_MCU_LM3S6965)
  LM3S69XX_PIN_UART_RX(LM3S69XX_PORT_D, 2),
  LM3S69XX_PIN_UART_TX(LM3S69XX_PORT_D, 3),
#elif defined(LM3S69XX_MCU_LM4F120)
  LM3S69XX_PIN_UART_RX(LM3S69XX_PORT_B, 0),
  LM3S69XX_PIN_UART_TX(LM3S69XX_PORT_B, 1),
  LM3S69XX_PIN_UART_RTS(LM3S69XX_PORT_C, 4),
  LM3S69XX_PIN_UART_CTS(LM3S69XX_PORT_C, 5),
#elif defined(LM3S69XX_MCU_TM4C129E)
  LM3S69XX_PIN_UART_RX(LM3S69XX_PORT_B, 0),
  LM3S69XX_PIN_UART_TX(LM3S69XX_PORT_B, 1),
  LM3S69XX_PIN_UART_RTS(LM3S69XX_PORT_E, 0),
  LM3S69XX_PIN_UART_RI(LM3S69XX_PORT_E, 4),
  LM3S69XX_PIN_UART_DTR(LM3S69XX_PORT_E, 3),
  LM3S69XX_PIN_UART_DSR(LM3S69XX_PORT_E, 1),
  LM3S69XX_PIN_UART_DCD(LM3S69XX_PORT_E, 2),
  LM3S69XX_PIN_UART_CTS(LM3S69XX_PORT_N, 1),
  
  LM3S69XX_PIN_UART_RX(LM3S69XX_PORT_Q, 4),
  LM3S69XX_PIN_UART_RTS(LM3S69XX_PORT_N, 0),
  LM3S69XX_PIN_UART_RI(LM3S69XX_PORT_N, 5),
  LM3S69XX_PIN_UART_DTR(LM3S69XX_PORT_N, 4),
  LM3S69XX_PIN_UART_DSR(LM3S69XX_PORT_N, 3),
  LM3S69XX_PIN_UART_DCD(LM3S69XX_PORT_N, 2),
  LM3S69XX_PIN_UART_CTS(LM3S69XX_PORT_P, 3),
#else
#error No GPIO pin configuration for UART 1
#endif
#endif /* LM3S69XX_ENABLE_UART_1 */

#ifdef LM3S69XX_ENABLE_UART_2
#if defined(LM3S69XX_MCU_LM3S3749)
  LM3S69XX_PIN_UART_RX(LM3S69XX_PORT_D, 0),
  LM3S69XX_PIN_UART_TX(LM3S69XX_PORT_D, 1),
#elif defined(LM3S69XX_MCU_LM3S6965)
  LM3S69XX_PIN_UART_RX(LM3S69XX_PORT_G, 0),
  LM3S69XX_PIN_UART_TX(LM3S69XX_PORT_G, 1),
#elif defined(LM3S69XX_MCU_TM4C129E)
  LM3S69XX_PIN_UART_RX(LM3S69XX_PORT_A, 6),
  LM3S69XX_PIN_UART_TX(LM3S69XX_PORT_A, 7),
  LM3S69XX_PIN_UART_RTS(LM3S69XX_PORT_D, 6),
  LM3S69XX_PIN_UART_CTS(LM3S69XX_PORT_D, 7),
#else
#error No GPIO pin configuration for UART 2
#endif
#endif /* LM3S69XX_ENABLE_UART_2 */
};

static void init_gpio(void)
{
 #if !defined(LM3S69XX_MCU_TM4C129E)
 #if LM3S69XX_USE_AHB_FOR_GPIO
  volatile lm3s69xx_syscon *syscon = LM3S69XX_SYSCON;

  syscon->gpiohbctl |= SYSCONGPIOHBCTL_PORTA | SYSCONGPIOHBCTL_PORTB
      | SYSCONGPIOHBCTL_PORTC | SYSCONGPIOHBCTL_PORTD
      | SYSCONGPIOHBCTL_PORTE | SYSCONGPIOHBCTL_PORTF
#if LM3S69XX_NUM_GPIO_BLOCKS > 6
      | SYSCONGPIOHBCTL_PORTG
#if LM3S69XX_NUM_GPIO_BLOCKS > 7
      | SYSCONGPIOHBCTL_PORTH 
#endif
#endif
#endif
      ;
#endif /* LM3S69XX_USE_AHB_FOR_GPIO */


  lm3s69xx_gpio_set_config_array(start_config_gpio,
      sizeof(start_config_gpio) / sizeof(start_config_gpio[0]));

}

void bsp_start(void)
{
  init_main_osc();
  init_gpio();
  bsp_interrupt_initialize();
}
