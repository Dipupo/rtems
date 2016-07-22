/*
 * Copyright © 2013 Eugeniy Meshcheryakov <eugen@debian.org>
 *
 * The license and distribution terms for this file may be
 * found in the file LICENSE in this distribution or at
 * http://www.rtems.org/license/LICENSE.
 */

#include <bsp/syscon.h>
#include <bsp/lm3s69xx.h>
#include <rtems.h>

static void delay_3_clocks(void)
{
  asm volatile(
      "nop\n\t"
      "nop\n\t"
      "nop");
}

void __attribute__((naked)) lm3s69xx_syscon_delay_3x_clocks(unsigned long x_count)
{
    asm volatile(
                 "subs  r0, #1\n\t"
                 "bne   lm3s69xx_syscon_delay_3x_clocks\n\t"
                 "bx    lr"
                 );
}

void lm3s69xx_syscon_enable_gpio_clock(unsigned int port, bool enable)
{
  volatile lm3s69xx_syscon *syscon = LM3S69XX_SYSCON;
  uint32_t mask = 1 << port;
  rtems_interrupt_level level;

  rtems_interrupt_disable(level);

  if (enable)
    syscon->rcgcgpio |= mask;
  else
    syscon->rcgcgpio &= ~mask;

  delay_3_clocks();

  rtems_interrupt_enable(level);
}

void lm3s69xx_syscon_enable_uart_clock(unsigned int port, bool enable)
{
  volatile lm3s69xx_syscon *syscon = LM3S69XX_SYSCON;
  uint32_t mask = 1 << port;
  rtems_interrupt_level level;

  rtems_interrupt_disable(level);

  if (enable)
    syscon->rcgcuart |= mask;
  else
    syscon->rcgcuart &= ~mask;

  delay_3_clocks();

  rtems_interrupt_enable(level);
}

void lm3s69xx_syscon_enable_ssi_clock(unsigned int port, bool enable)
{
  volatile lm3s69xx_syscon *syscon = LM3S69XX_SYSCON;
  uint32_t mask = 1 << port;
  rtems_interrupt_level level;

  rtems_interrupt_disable(level);

  if (enable)
    syscon->rcgcssi |= mask;
  else
    syscon->rcgcssi &= ~mask;

  delay_3_clocks();

  rtems_interrupt_enable(level);
}

void lm3s69xx_syscon_enable_pwm_clock(unsigned int port, bool enable)
{
  volatile lm3s69xx_syscon *syscon = LM3S69XX_SYSCON;
  uint32_t mask = 1 << port;
  rtems_interrupt_level level;

  rtems_interrupt_disable(level);

  if (enable)
    syscon->rcgcpwm |= mask;
  else
    syscon->rcgcpwm &= ~mask;

  delay_3_clocks();

  rtems_interrupt_enable(level);
}

/**
 * Sets PWMDIV field in the RCC register.
 *
 * @note div should be one of SCRCC_PWMDIV_DIV?_VAL constants.
 */
 void lm3s69xx_pwm_set_pwmdiv(unsigned int div)
{
  volatile lm3s69xx_pwm *pwm = LM3S69XX_PWM_0;
  rtems_interrupt_level level;

  rtems_interrupt_disable(level);
  pwm->cc = (pwm->cc & ~PWMCC_PWMDIV_MSK) | PWMCC_PWMDIV(div)
      | PWMCC_USEPWM;
  
  rtems_interrupt_enable(level);
} 
