/*
 * soft_pwm.h
 *
 * Created: 1/28/2023 4:27:09 PM
 *  Author: Hamsa
 */ 


#ifndef SOFT_PWM_H_
#define SOFT_PWM_H_

#include "io_define.h"

#define MAX_CHANNEL_NUM		5
#define MAX_PERIOD_COUNT	50

 typedef struct
 {
	 Gpio* gpio;
	 uint8_t channel;
	 uint8_t duty;
 }SoftPwmChannnel;

void softPwmAdd (SoftPwmChannnel* channel);
void softPwmInit (void);
void softDeinit (void);
void softPwmSetDuty (SoftPwmChannnel* channel, uint8_t duty);
// Call this function every 1ms
void softPwmISR (void);


#endif /* SOFT_PWM_H_ */