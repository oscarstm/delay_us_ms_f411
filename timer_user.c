/*
 * timer_user.c
 *
 *  Created on: Mar 11, 2026
 *      Author: oscar
 */

#include "timer_user.h"

void delay_us(uint16_t us) {

	if (us == 0) {
		return;
	}

	RCC->APB2ENR |= RCC_APB2ENR_TIM9EN;

	TIM9->CR1 &= ~TIM_CR1_CEN;
	TIM9->SR = 0;
	TIM9->CNT = 0;
	TIM9->PSC = 100 - 1; // 100 MHz / 100 = 1 MHz == 1 us
	TIM9->ARR = us - 1;
	TIM9->CR1 |= TIM_CR1_CEN;

	while ((TIM9->SR & TIM_SR_UIF) == 0) {
		//
	}
}

void delay_ms(uint16_t ms) {
	uint16_t i;

	for (i = 0; i < ms; i++) {
		delay_us(1000);
	}
}
