/*
 * io_define.h
 *
 * Created: 1/28/2023 4:27:41 PM
 *  Author: Hamsa
 */ 


#ifndef IO_DEFINE_H_
#define IO_DEFINE_H_

#include <stdint.h>

#include <avr/io.h>
#include <stdint.h>

typedef struct {
	uint8_t bit0 : 1;
	uint8_t bit1 : 1;
	uint8_t bit2 : 1;
	uint8_t bit3 : 1;
	uint8_t bit4 : 1;
	uint8_t bit5 : 1;
	uint8_t bit6 : 1;
	uint8_t bit7 : 1;
} BitAccess;

typedef union{
	BitAccess bits;
	uint8_t reg;
}Register;

typedef struct{
	Register PIN;
	Register DDR;
	Register PORT;
}Gpio;


#define GPIOA (*(Gpio*)0x3A)
#define GPIOB (*(Gpio*)0x36)
#define GPIOC (*(Gpio*)0x33)
#define GPIOD (*(Gpio*)0x30)

#endif /* IO_DEFINE_H_ */