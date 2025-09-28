// STM32L432KC_RCC.c
// Source code for RCC functions

#include "STM32L432KC_RCC.h"

void configureMSI(void) {
//RCC->CR |= (1 << 0) is the same as RCC->CR = RCC->CR | mask; // OR with mask to set bit 1, do AND with ~mask to set to 0
    RCC->CR &= ~(1 << 0); // turn MSI off 
    RCC->CR |= (1 << 0); // turn MSI on

    while ((RCC->CR >> 1 & 1) != 1); // leave loop only if MSIREADY (bit 1) is HIGH 
}

void configureClock(void){
    // Configure and turn on MSI
    configureMSI();
  
    // set MSI as clock source (RCC_CFGR)
    RCC->CFGR &= ~(0b00 << 0); // set SW to 00 for MSI
    while((RCC->CFGR & (0b11 << 2)) != (0b00 << 2));  // verify that SW is set to 00 for MSI
}
