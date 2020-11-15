/*
 * func_port.h
 *
 * Created: 2020/11/14 18:41:02
 * Project: FuncDecoder_Bipoler_Tiny45
 * Version: 1.00
 *	Target:	ATtiny45
 *	Author: Y.Tsurui
 */ 

#define FUNC_PORT_PORT			PORTB
#define FUNC_PORT_DDR			DDRB
#define FUNC_PORT_PIN			PINB

#define FUNC_PORT_FOR_PIN		PB3
#define FUNC_PORT_REV_PIN		PB4
#define FUNC_PORT_EN_PIN		PB1

//#define FUNC_PORT_PIN1			PB1		// Func1_For
//#define FUNC_PORT_PIN2			PB2		// Func1_Rev
//#define FUNC_PORT_PIN3			PB3		// Func2
//#define DIR_REVERSE_JUMPER		PB4		// Direction Reverse Jumper

//#define FUNC_PORT_PIN1_MASK		(1 << FUNC_PORT_PIN1)
//#define FUNC_PORT_PIN2_MASK		(1 << FUNC_PORT_PIN2)
//#define FUNC_PORT_PIN3_MASK		(1 << FUNC_PORT_PIN3)
//#define DIR_REVERSE_JUMPER_MASK	(1 << DIR_REVERSE_JUMPER)

#define FUNC_PORT_FOR_MASK		(1 << FUNC_PORT_FOR_PIN)
#define FUNC_PORT_REV_MASK		(1 << FUNC_PORT_REV_PIN)
#define FUNC_PORT_EN_MASK		(1 << FUNC_PORT_EN_PIN)

//#define FUNC_PORT_DDR_MASK		FUNC_PORT_PIN1_MASK | FUNC_PORT_PIN2_MASK | FUNC_PORT_PIN3_MASK
#define FUNC_PORT_DDR_MASK		FUNC_PORT_FOR_MASK | FUNC_PORT_REV_MASK | FUNC_PORT_EN_MASK

void init_func_port();
void func_ctrl(uint8_t func_num, uint8_t func_stat);
void func_en_ctrl(uint8_t func_stat);
uint8_t readDirectionReverse(void);
