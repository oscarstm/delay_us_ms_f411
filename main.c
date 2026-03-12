#include "stm32f4xx.h"
#include "clk_user.h"
#include "timer_user.h"
#include "gpio_test.h"

int main(void) {
	clk_user_init();
	gpio_init();

	while (1) {
		GPIOB->BSRR |= GPIO_BSRR_BS_2;
		delay_ms(500);
		GPIOB->BSRR |= GPIO_BSRR_BR_2;
		delay_ms(500);
	}

}

