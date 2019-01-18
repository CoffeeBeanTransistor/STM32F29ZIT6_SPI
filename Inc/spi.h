#ifndef __SPI_H__
#define __SPI_H__

#include <stdio.h>
#include "common.h"

typedef struct SpiReg SpiReg;
struct SpiReg {
	IoRegister CR1;					//0x00	Control Register 1
	IoRegister CR2;					//0x04	Control Register 2
	IoRegister SR;		    		//0x08	Status Register 2
	IoRegister DR;					//0x0C	Data Register
	IoRegister CRCPR;				//0x10	CRC Polynomial Register
	IoRegister RXCRCR;				//0x14	RX CRC Register
	IoRegister TXCRCR;				//0x18	TX CRC Register
	IoRegister I2SCFGR;				//0x1C	I2S Configuration Register
	IoRegister I2SPR;				//0x20	I2S Prescaler Register
};

//Live on APB2 and don't support I2S
#define spi1	((SpiReg *)0x40013000)
#define spi4    ((SpiReg *)0x40013400)

//Live on APB1 and support I2S
#define spi2	((SpiReg *)0x40003800)
#define spi3 	((SpiReg *)0x40003C00)

//Control Register 1
//Bidirectional Data Mode Enable
#define SPI_2L_UNIDIRECTIONAL_DATA					(0ULL << 15)
#define SPI_1L_BIDIRECTIONAL_DATA					(1ULL << 15)

//Output Enable in Bidirectional Mode
#define SPI_UNI_DATA_RECEIVE_ONLY					(0ULL << 14)
#define SPI_UNI_DATA_TRANSMIT_ONLY					(1ULL << 14)

//Hardware CRC Calculation Enable (Write when SPE = 0)
#define SPI_CRC_CAL_DISABLE							(0ULL << 13)
#define SPI_CRC_CAL_ENABLE							(1ULL << 13)

//CRC Transfer Next
#define SPI_NO_CRC_NEXT_TRANSFER					(0ULL << 12)
#define SPI_CRC_NEXT_TRANSFER						(1ULL << 12)

//Data Frame Format
#define SPI_8_BIT_DATA_FRAME						(0ULL << 11)
#define SPI_16_BIT_DATA_FRAME						(1ULL << 11)

//Receive Only (Use only when 2 Lines Unidirectional Mode)
#define SPI_FULL_DUPLEX								(0ULL << 10)
#define SPI_RECEIVE_ONLY							(1ULL << 10)

//Software Slave Management
#define SPI_SOFTWARE_SLAVE_MGMT_DISABLE				(0ULL << 9)
#define SPI_SOFTWARE_SLAVE_MGMT_ENABLE				(1ULL << 9)

//Frame Format
#define SPI_MSB_TRANSMIT_FIRST						(0ULL << 7)
#define SPI_LSB_TRANSMIT_FIRST						(1ULL << 7)

//SPI Enable
#define SPI_DISABLE									(0ULL << 6)
#define SPI_ENABLE									(1ULL << 6)

//Baud Rate Control
#define SPI_BAUD_FCLK_DIV_BY_2						(0ULL << 3)
#define SPI_BAUD_FCLK_DIV_BY_4						(1ULL << 3)
#define SPI_BAUD_FCLK_DIV_BY_8						(2ULL << 3)
#define SPI_BAUD_FCLK_DIV_BY_16						(3ULL << 3)
#define SPI_BAUD_FCLK_DIV_BY_32						(4ULL << 3)
#define SPI_BAUD_FCLK_DIV_BY_64						(5ULL << 3)
#define SPI_BAUD_FCLK_DIV_BY_128					(6ULL << 3)
#define SPI_BAUD_FCLK_DIV_BY_256					(7ULL << 3)

//Master Selection
#define SPI_SLAVE_CONFIG							(0ULL << 2)
#define SPI_MASTER_CONFIG							(1ULL << 2)

//Clock Polarity
#define SPI_CK_TO_0_WHEN_IDLE						(0ULL << 1)
#define SPI_CK_TO_1_WHEN_IDLE						(1ULL << 1)

//Clock Phase
#define SPI_FIRST_CLK_TRANS_CAPTURE_EDGE			(0ULL << 0)
#define SPI_SECOND_CLK_TRANS_CAPTURE_EDGE			(1ULL << 0)


//Control Register 2
//TX Buffer Empty Interrupt Enable
#define SPI_TXE_INT_DISABLE							(0ULL << 23)
#define SPI_TXE_INT_ENABLE							(1ULL << 23)

//RX Buffer Not Empty Interrupt Enable
#define SPI_RXNE_INT_DISABLE						(0ULL << 22)
#define SPI_RXNE_INT_ENABLE							(1ULL << 22)

//Error Interrupt Enable
#define SPI_ERR_INT_DISABLE							(0ULL << 21)
#define SPI_ERR_INT_ENABLE							(1ULL << 21)

//Frame Format
#define SPI_MOTOROLA_MODE							(0ULL << 20)
#define SPI_TI_MODE									(1ULL << 20)

//Slave Select Output Enable
#define SPI_SS_OUTPUT_DISABLE						(0ULL << 18)
#define SPI_SS_OUTPUT_ENABLE						(1ULL << 18)

//TX Buffer DMA Enable
#define SPI_TX_DMA_DISABLE							(0ULL << 17)
#define SPI_TX_DMA_ENABLE							(1ULL << 17)

//RX Buffer DMA Enable
#define SPI_RX_DMA_DISABLE							(0ULL << 16)
#define SPI_RX_DMA_ENABLE							(1ULL << 16)


//Status Register
#define SPI_FRE			(1 << 8) //Frame Format Error
#define SPI_BSY			(1 << 7) //Busy Flag
#define SPI_OVR			(1 << 6) //Overrun Flag
#define SPI_MODF		(1 << 5) //Mode Fault
#define SPI_CRCERR		(1 << 4) //CRC Error Flag
#define SPI_UDR			(1 << 3) //Underrun Flag
#define SPI_CHSIDE		(1 << 2) //Channel Side Flag
#define SPI_TXE			(1 << 1) //Transmit Empty Flag
#define SPI_RXNE		(1 << 0) //Receive Not Empty Flag

//MACROS
#define SPI_GET_STATUS(spi, flag)				((spi)->SR & (flag))
#define SPI_CLEAR_CRC_ERROR(spi)				((spi)->SR &= ~(SPI_CRCERR))
#define SPI_IS_TX_REG_EMPTY(spi)				(SPI_GET_STATUS(spi, SPI_TXE))
#define SPI_IS_RX_REG_NOT_EMPTY(spi)			(SPI_GET_STATUS(spi, SPI_RXNE))
#define SPI_SET_CRC_POLY_VALUE(spi, num)			\
					do {							\
						(spi)->CRCPR &= ~(0xffff);	\
						(spi)->CRCPR |= num;		\
					}while(0) //0007h is reset value

void spiConfigure(SpiReg *spi, long mode);

#endif //__SPI_H__
