#include <avr/io.h>
#include <avr/interrupt.h>
#include <avr/delay.h>
#include "soft_pwm.h"

int main(void)
{
	uint8_t myDuty = 0;
	uint8_t delayCnt = 0;
	
	SoftPwmChannnel channel_1 = {
		.duty = 5,
		.gpio = &GPIOC,
		.channel = 0,
	};
	SoftPwmChannnel channel_2 = {
		.duty = 50,
		.gpio = &GPIOC,
		.channel = 1,
	};
	SoftPwmChannnel channel_3 = {
		.duty = 90,
		.gpio = &GPIOC,
		.channel = 2,
	};
	softPwmAdd(&channel_1);
	softPwmAdd(&channel_2);
	softPwmAdd(&channel_3);
	
	softPwmInit(); 
		
    while (1) 
    {
		if(delayCnt >= 200)
		{
			delayCnt = 0;
			softPwmSetDuty(&channel_1, myDuty++);
		}
		softPwmISR();
		_delay_ms(1);
		delayCnt++;
		
    }
}

