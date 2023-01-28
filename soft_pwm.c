/*
 * soft_pwm.c
 *
 * Created: 1/28/2023 4:26:58 PM
 *  Author: Hamsa
 */ 

#include "soft_pwm.h"
#include <avr/io.h>

static SoftPwmChannnel* channelBuff[MAX_CHANNEL_NUM];
static uint8_t lastChannelNum = 0;
static uint16_t period = 0;

void softPwmAdd (SoftPwmChannnel* channel)
{
	if(lastChannelNum < MAX_CHANNEL_NUM)
	{
		channelBuff[lastChannelNum] = channel;
		lastChannelNum++;
	}
}

void softPwmInit (void)
{
	for (uint8_t i = 0; i < lastChannelNum; i++)
	{
		channelBuff[i]->gpio->DDR.reg |= 1 << channelBuff[i]->channel;
	}
}

void softDeinit (void)
{
	softPwmInit();
}

void softPwmSetDuty (SoftPwmChannnel* channel, uint8_t duty)
{
	channel->duty = duty > 100 ? 100 : duty;
}

void softPwmISR (void)
{
	if(++period >= MAX_PERIOD_COUNT)
	{
		period = 0;
	}
	
	for (uint8_t i = 0; i < lastChannelNum; i++)
	{
		uint8_t duty = (channelBuff[i]->duty * MAX_PERIOD_COUNT) / 100;
		if(period < duty)
		{
			channelBuff[i]->gpio->PORT.reg |= (1 << channelBuff[i]->channel);
		}
		else
		{
			channelBuff[i]->gpio->PORT.reg &= ~(1 << channelBuff[i]->channel);
		}
	}
}