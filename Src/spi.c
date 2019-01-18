#include "spi.h"
#include "common.h"
#include <stdio.h>

void spiConfigure(SpiReg *spi, long mode) {
	spi->CR1 = (uint32_t)(mode & 0xffff);
	spi->CR2 = (uint32_t)((mode >> 16) & 0xffff);
}
