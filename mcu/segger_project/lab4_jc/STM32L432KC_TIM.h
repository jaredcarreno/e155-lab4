//STM32L432KC_TIM.h
// Header for Timer functions

#ifndef STM32L4_TIM_H
#define STM32L4_TIM_H

#include <stdint.h>

////////////////////////////////////////
// Definitions
////////////////////////////////////////

#define __IO volatile

#define ticks_per_ms 10
#define ticks_per_ms_freq 10000


// BASE ADDRESSES
#define RCC_BASE (0x40021000UL) // base address of RCC
#define TIM15_BASE (0x40014000UL)
#define TIM16_BASE (0x40014400UL)

/**
  * @brief Reset and Clock Control
  */

typedef struct
{
  __IO uint32_t CR1; /* Address Offset: 0x00 */
  __IO uint32_t CR2; /* Address Offset: 0x04 */
  __IO uint32_t SMCR; /* Address Offset: 0x08 */
  __IO uint32_t DIER; /* Address Offset: 0x0C */
  __IO uint32_t SR; /* Address Offset: 0x10 */
  __IO uint32_t EGR; /* Address Offset: 0x14 */
  __IO uint32_t CCMR1; /* Address Offset: 0x18 */
    uint32_t RESERVED0; /* Address Offset: 0x1C */
  __IO uint32_t CCER; /* Address Offset: 0x20 */
  __IO uint32_t CNT; /* Address Offset: 0x24 */
  __IO uint32_t PSC; /* Address Offset: 0x28 */
  __IO uint32_t ARR; /* Address Offset: 0x2C */
  __IO uint32_t RCR; /* Address Offset: 0x30 */
  __IO uint32_t CCR1; /* Address Offset: 0x34 */
  __IO uint32_t CCR2; /* Address Offset: 0x38 */
    uint32_t RESERVED1; /* Address Offset: 0x3C */
    uint32_t RESERVED2; /* Address Offset: 0x40 */
  __IO uint32_t BDTR; /* Address Offset: 0x44 */
  __IO uint32_t DCR; /* Address Offset: 0x48 */
  __IO uint32_t DMAR; /* Address Offset: 0x4C */
  __IO uint32_t OR1; /* Address Offset: 0x50 */
    uint32_t RESERVED3; /* Address Offset: 0x54 */
    uint32_t RESERVED4; /* Address Offset: 0x58 */
    uint32_t RESERVED5; /* Address Offset: 0x5C */
  __IO uint32_t OR2; /* Address Offset: 0x60 */
} TIM_TypeDef;

#define TIM15 ((TIM_TypeDef *) TIM15_BASE)
#define TIM16 ((TIM_TypeDef *) TIM16_BASE)

///////////////////////////////////////
// Function prototypes
///////////////////////////////////////

void initTIM(TIM_TypeDef * TIMx);

void delay_millis(TIM_TypeDef * TIMx, uint32_t ms);

void initPWM(TIM_TypeDef * TIMx);

void playFreq(TIM_TypeDef * TIMx, uint32_t freq);
#endif