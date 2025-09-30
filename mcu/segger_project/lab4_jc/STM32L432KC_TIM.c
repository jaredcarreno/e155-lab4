// STM32L432KC_TIM.c
// Source code for RCC functions

#include "STM32L432KC_TIM.h"

void initTIM(TIM_TypeDef * TIMx) {
  TIMx->PSC = 7; // set prescale

  TIMx->CR1 |= (1 << 7); // ARPE high

  TIMx->EGR |= (1 << 0); // update generation high

  TIMx->CR1 |= (1 << 0); // CEN high
}

void delay_millis(TIM_TypeDef * TIMx, uint32_t ms) {
  uint16_t ARR_calculated = ms*ticks_per_ms;

  TIMx->CNT = 0; // set CNT[15:0] to all zeroes

  TIMx->ARR = (ARR_calculated); // set ARR

  TIMx->SR &= ~(1 << 0); // clear UIF
  
  TIMx->EGR |= (1 << 0); // update generation 

  while(!(TIMx->SR & (1 << 0))) { // while flag not high
  }

  TIMx->SR &= ~(1 << 0); // clear flag
}

void initPWM(TIM_TypeDef * TIMx) {
  TIMx->PSC = 7; // set prescale
  TIMx->CCMR1 |= (0b110 << 4); // set to PWM output mode
  TIMx->CCMR1 |= (1 << 3); //Preload register on TIMx_CCR1 enabled. TIMx_CCR1 preload value is loaded in the active register at each update event
  TIMx->CR1 |= (1 << 7);  // Set ARPE bit in TIMx_CR1 register HIGH
  
  TIMx->CCER &= ~(1 << 1); // Set Active Low (polarity)
  TIMx->CCER |= (1 << 0); // setting CC1E to output
  //TIMx->CCER |= (1 << 2); // setting CC1NE to output
  TIMx->BDTR |= (1 << 15); // setting MOE to HIGH (outputs enabled)
  //TIMx->BDTR |= (1 << 11); // setting OSSR to HIGH

  TIMx->EGR |= (1 << 0); // Setting update generation HIGH
  TIMx->CR1 |= (1 << 0); // Enable Timer
}

void playFreq(TIM_TypeDef * TIMx, uint32_t freq) {
  uint16_t ARR_calculated2 = ((1/freq)*1000)*ticks_per_ms;

  if (freq == 0) {
    TIMx->CR1 &= ~(1 << 0); // Disable timer
    TIMx->EGR |= (1 << 0); // Setting update generation HIGH
  }

  else {
    TIMx->CR1 |= (1 << 0); // Enable Timer
    TIMx->ARR = (ARR_calculated2); // updated ARR
    TIMx->CCR1 = ARR_calculated2/2; // when counter reaches half of the goal, set wave low (duty cycle = 50%)
    TIMx->EGR |= (1 << 0); // Setting update generation HIGH
  }
}