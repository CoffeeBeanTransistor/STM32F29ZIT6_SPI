#ifndef __RCC_H__
#define __RCC_H__
#include <stdio.h>
#include "Common.h"

typedef struct RccRegs RccRegs;
struct RccRegs {
	IoRegister CR;						//0x00 Control Reg
	IoRegister PLLCFGR;					//0x04 PLL Config Reg
	IoRegister CFGR;				    //0x08 Clock Config Reg
	IoRegister CIR;						//0x0C Clock Interrupt Reg
	IoRegister AHB1RSTR;				//0x10 AHB1 Peripheral Reset Reg
	IoRegister AHB2RSTR;				//0x14 AHB2 Peripheral Reset Reg
	IoRegister AHB3RSTR;				//0x18 AHB3 Peripheral Reset Reg
	IoRegister Reserved0;				//0x1C Reserved
	IoRegister APB1RSTR;				//0x20 APB1 Peripheral Reset Reg
	IoRegister APB2RSTR;				//0x24 APB2 Peripheral Reset Reg
	IoRegister Reserved1[2];			//0x28 Reserved
	IoRegister AHB1ENR;					//0x30 AHB1 Peripheral Clock Reg
	IoRegister AHB2ENR;					//0x34 AHB2 Peripheral Clock Reg
	IoRegister AHB3ENR;					//0x38 AHB3 Peripheral Clock Reg
	IoRegister Reserved2;				//0x3C Reserved
	IoRegister APB1ENR;					//0x40 APB1 Peripheral Clock Reg
	IoRegister APB2ENR;					//0x44 APB2 Peripheral Clock Reg
	IoRegister Reserved3[2];			//0x48 Reserved
	IoRegister AHB1ELPENR;				//0x50 AHB1 Peripheral Low Power Clock Reg
	IoRegister AHB2ELPENR;				//0x54 AHB2 Peripheral Low Power Clock Reg
	IoRegister AHB3ELPENR;				//0x58 AHB3 Peripheral Low Power Clock Reg
	IoRegister Reserved4;				//0x5C Reserved
	IoRegister APB1ELPENR;				//0x60 APB1 Peripheral Low Power Clock Reg
	IoRegister APB2ELPENR;				//0x64 APB2 Peripheral Low Power Clock Reg
	IoRegister Reserved5[2];			//0x68 Reserved
	IoRegister BDCR;					//0x70 Backup Domain Con Reg
	IoRegister CSR;						//0x74 Clock Con & Status Reg
	IoRegister Reserved6[2];			//0x78 Reserved
	IoRegister SSCGR;					//0x80 Spread Spectrum Clock Gen Reg
	IoRegister PLL12SCFGR;				//0x84 PLLI2S Config Reg
};

//RCC Pointers
#define rcc										((RccRegs *)0x40023800)

//SPI
#define ENABLE_SPI1_CLK_GATING()				rcc->APB2ENR |= (1 << 12)
#define ENABLE_SPI2_CLK_GATING()				rcc->APB1ENR |= (1 << 14)
#define ENABLE_SPI3_CLK_GATING()				rcc->APB1ENR |= (1 << 15)

#define DISABLE_SPI1_CLK_GATING()				rcc->APB2ENR &= ~(1 << 12)
#define DISABLE_SPI2_CLK_GATING()				rcc->APB1ENR &= ~(1 << 14)
#define DISABLE_SPI3_CLK_GATING()				rcc->APB1ENR &= ~(1 << 15)

#define RESET_SPI1()							rcc->APB2RSTR |= (1 << 12)
#define RESET_SPI2()							rcc->APB1RSTR |= (1 << 14)
#define RESET_SPI3()							rcc->APB1RSTR |= (1 << 15)

#define UNRESET_SPI1()							rcc->APB2RSTR &= ~(1 << 12)
#define UNRESET_SPI2()							rcc->APB1RSTR &= ~(1 << 14)
#define UNRESET_SPI3()							rcc->APB1RSTR &= ~(1 << 15)

//TIMER
#define ENABLE_TIMER_2_CLK_GATING()				rcc->APB1ENR |= (1 << 0)
#define ENABLE_TIMER_3_CLK_GATING()				rcc->APB1ENR |= (1 << 1)
#define ENABLE_TIMER_4_CLK_GATING()				rcc->APB1ENR |= (1 << 2)
#define ENABLE_TIMER_5_CLK_GATING()				rcc->APB1ENR |= (1 << 3)
#define ENABLE_TIMER_6_CLK_GATING()				rcc->APB1ENR |= (1 << 4)
#define ENABLE_TIMER_7_CLK_GATING()				rcc->APB1ENR |= (1 << 5)
#define ENABLE_TIMER_12_CLK_GATING()			rcc->APB1ENR |= (1 << 6)
#define ENABLE_TIMER_13_CLK_GATING()			rcc->APB1ENR |= (1 << 7)
#define ENABLE_TIMER_14_CLK_GATING()			rcc->APB1ENR |= (1 << 8)

#define DISABLE_TIMER_2_CLK_GATING()			rcc->APB1ENR &= ~(1 << 0)
#define DISABLE_TIMER_3_CLK_GATING()			rcc->APB1ENR &= ~(1 << 1)
#define DISABLE_TIMER_4_CLK_GATING()			rcc->APB1ENR &= ~(1 << 2)
#define DISABLE_TIMER_5_CLK_GATING()			rcc->APB1ENR &= ~(1 << 3)
#define DISABLE_TIMER_6_CLK_GATING()			rcc->APB1ENR &= ~(1 << 4)
#define DISABLE_TIMER_7_CLK_GATING()			rcc->APB1ENR &= ~(1 << 5)
#define DISABLE_TIMER_12_CLK_GATING()			rcc->APB1ENR &= ~(1 << 6)
#define DISABLE_TIMER_13_CLK_GATING()			rcc->APB1ENR &= ~(1 << 7)
#define DISABLE_TIMER_14_CLK_GATING()			rcc->APB1ENR &= ~(1 << 8)

#define RESET_TIMER_2()							rcc->APB1RSTR |= (1 << 0)
#define RESET_TIMER_3()							rcc->APB1RSTR |= (1 << 1)
#define RESET_TIMER_4()							rcc->APB1RSTR |= (1 << 2)
#define RESET_TIMER_5()							rcc->APB1RSTR |= (1 << 3)
#define RESET_TIMER_6()							rcc->APB1RSTR |= (1 << 4)
#define RESET_TIMER_7()							rcc->APB1RSTR |= (1 << 5)
#define RESET_TIMER_12()						rcc->APB1RSTR |= (1 << 6)
#define RESET_TIMER_13()						rcc->APB1RSTR |= (1 << 7)
#define RESET_TIMER_14()						rcc->APB1RSTR |= (1 << 8)

#define UNRESET_TIMER_2()						rcc->APB1RSTR &= ~(1 << 0)
#define UNRESET_TIMER_3()						rcc->APB1RSTR &= ~(1 << 1)
#define UNRESET_TIMER_4()						rcc->APB1RSTR &= ~(1 << 2)
#define UNRESET_TIMER_5()						rcc->APB1RSTR &= ~(1 << 3)
#define UNRESET_TIMER_6()						rcc->APB1RSTR &= ~(1 << 4)
#define UNRESET_TIMER_7()						rcc->APB1RSTR &= ~(1 << 5)
#define UNRESET_TIMER_12()						rcc->APB1RSTR &= ~(1 << 6)
#define UNRESET_TIMER_13()						rcc->APB1RSTR &= ~(1 << 7)
#define UNRESET_TIMER_14()						rcc->APB1RSTR &= ~(1 << 8)

//DMA
#define ENABLE_DMA1_CLK_GATING()				rcc->AHB1ENR |= (1 << 21)
#define ENABLE_DMA2_CLK_GATING()				rcc->AHB1ENR |= (1 << 22)

#define DISABLE_DMA1_CLK_GATING()				rcc->AHB1ENR &= ~(1 << 21)
#define DISABLE_DMA2_CLK_GATING()				rcc->AHB1ENR &= ~(1 << 22)

#define RESET_DMA1()							rcc->AHB1RSTR |= (1 << 21)
#define RESET_DMA2()							rcc->AHB1RSTR |= (1 << 22)

#define UNRESET_DMA1()							rcc->AHB1RSTR &= ~(1 << 21)
#define UNRESET_DMA2()							rcc->AHB1RSTR &= ~(1 << 22)

//GPIO
#define ENABLE_GPIOA_CLK_GATING()				rcc->AHB1ENR |= (1 << 0)
#define ENABLE_GPIOB_CLK_GATING()				rcc->AHB1ENR |= (1 << 1)
#define ENABLE_GPIOC_CLK_GATING()				rcc->AHB1ENR |= (1 << 2)
#define ENABLE_GPIOD_CLK_GATING()				rcc->AHB1ENR |= (1 << 3)
#define ENABLE_GPIOE_CLK_GATING()				rcc->AHB1ENR |= (1 << 4)
#define ENABLE_GPIOF_CLK_GATING()				rcc->AHB1ENR |= (1 << 5)
#define ENABLE_GPIOG_CLK_GATING()				rcc->AHB1ENR |= (1 << 6)
#define ENABLE_GPIOH_CLK_GATING()				rcc->AHB1ENR |= (1 << 7)
#define ENABLE_GPIOI_CLK_GATING()				rcc->AHB1ENR |= (1 << 8)
#define ENABLE_GPIOJ_CLK_GATING()				rcc->AHB1ENR |= (1 << 9)
#define ENABLE_GPIOK_CLK_GATING()				rcc->AHB1ENR |= (1 << 10)

#define DISABLE_GPIOA_CLK_GATING()				rcc->AHB1ENR &= ~(1 << 0)
#define DISABLE_GPIOB_CLK_GATING()				rcc->AHB1ENR &= ~(1 << 1)
#define DISABLE_GPIOC_CLK_GATING()				rcc->AHB1ENR &= ~(1 << 2)
#define DISABLE_GPIOD_CLK_GATING()				rcc->AHB1ENR &= ~(1 << 3)
#define DISABLE_GPIOE_CLK_GATING()				rcc->AHB1ENR &= ~(1 << 4)
#define DISABLE_GPIOF_CLK_GATING()				rcc->AHB1ENR &= ~(1 << 5)
#define DISABLE_GPIOG_CLK_GATING()				rcc->AHB1ENR &= ~(1 << 6)
#define DISABLE_GPIOH_CLK_GATING()				rcc->AHB1ENR &= ~(1 << 7)
#define DISABLE_GPIOI_CLK_GATING()				rcc->AHB1ENR &= ~(1 << 8)
#define DISABLE_GPIOJ_CLK_GATING()				rcc->AHB1ENR &= ~(1 << 9)
#define DISABLE_GPIOK_CLK_GATING()				rcc->AHB1ENR &= ~(1 << 10)

#define RESET_GPIOA()							rcc->AHB1RSTR |= (1 << 0)
#define RESET_GPIOB()							rcc->AHB1RSTR |= (1 << 1)
#define RESET_GPIOC()							rcc->AHB1RSTR |= (1 << 2)
#define RESET_GPIOD()							rcc->AHB1RSTR |= (1 << 3)
#define RESET_GPIOE()							rcc->AHB1RSTR |= (1 << 4)
#define RESET_GPIOF()							rcc->AHB1RSTR |= (1 << 5)
#define RESET_GPIOG()							rcc->AHB1RSTR |= (1 << 6)
#define RESET_GPIOH()							rcc->AHB1RSTR |= (1 << 7)
#define RESET_GPIOI()							rcc->AHB1RSTR |= (1 << 8)
#define RESET_GPIOJ()							rcc->AHB1RSTR |= (1 << 9)
#define RESET_GPIOK()							rcc->AHB1RSTR |= (1 << 10)

#define UNRESET_GPIOA()							rcc->AHB1RSTR &= ~(1 << 0)
#define UNRESET_GPIOB()							rcc->AHB1RSTR &= ~(1 << 1)
#define UNRESET_GPIOC()							rcc->AHB1RSTR &= ~(1 << 2)
#define UNRESET_GPIOD()							rcc->AHB1RSTR &= ~(1 << 3)
#define UNRESET_GPIOE()							rcc->AHB1RSTR &= ~(1 << 4)
#define UNRESET_GPIOF()							rcc->AHB1RSTR &= ~(1 << 5)
#define UNRESET_GPIOG()							rcc->AHB1RSTR &= ~(1 << 6)
#define UNRESET_GPIOH()							rcc->AHB1RSTR &= ~(1 << 7)
#define UNRESET_GPIOI()							rcc->AHB1RSTR &= ~(1 << 8)
#define UNRESET_GPIOJ()							rcc->AHB1RSTR &= ~(1 << 9)
#define UNRESET_GPIOK()							rcc->AHB1RSTR &= ~(1 << 10)

//USART
#define ENABLE_USART5_CLK_GATING()				rcc->APB1ENR |= (1 << 20)

#define DISABLE_USART5_CLK_GATING()				rcc->APB1ENR &= ~(1 << 20)

#define RESET_USART5()							rcc->APB1RSTR |= (1 << 20)

#define UNRESET_USART5()						rcc->APB1RSTR &= ~(1 << 20)

#endif //__RCC_H__
