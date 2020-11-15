/*
 * func_port.c
 *
 * Created: 2020/11/14 18:41:51
 * Project: FuncDecoder_Bipoler_Tiny45
 * Version: 1.0.0
 *  Target: Attiny45
 *  Author: Y.Tsurui
 */ 

#include <avr/io.h>
#include "func_port.h"

void init_func_port(void)
{
	FUNC_PORT_DDR |= FUNC_PORT_DDR_MASK;
	//FUNC_PORT_DDR &= ~DIR_REVERSE_JUMPER_MASK;
	FUNC_PORT_PORT &= ~FUNC_PORT_DDR_MASK;
	//FUNC_PORT_PORT |= DIR_REVERSE_JUMPER_MASK;
}

void func_ctrl(uint8_t func_num, uint8_t func_stat)
{
	uint8_t funcPin = 0;
	
	switch (func_num) {
		case 0:
			funcPin = FUNC_PORT_FOR_MASK;
			break;
		case 1:
			funcPin = FUNC_PORT_REV_MASK;
			break;
		default:
			return;
	}
	
	if (func_stat) {
		FUNC_PORT_PORT |= funcPin;
	} else {
		FUNC_PORT_PORT &= ~funcPin;
	}
		
}

void func_en_ctrl(uint8_t func_stat) {
	if (func_stat) {
		FUNC_PORT_PORT |= FUNC_PORT_EN_MASK;
	} else {
		FUNC_PORT_PORT &= ~FUNC_PORT_EN_MASK;
	}
}

uint8_t readDirectionReverse(void)
{
	//if (~PINB & DIR_REVERSE_JUMPER_MASK) {
	//	return (1);
	//}
	return (0);
}