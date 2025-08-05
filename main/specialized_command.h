
#ifndef SPECIALIZED_COMMAND_H
#define SPECIALIZED_COMMAND_H
#include "command.h"
#include <inttypes.h>
void wakeup();
void standby();
void reset();
void start();
void stop();
void RDATAC();
void SDATAC();
uint8_t* RDATA();
void WREG(uint8_t addr, uint8_t* data, uint8_t n);
uint8_t* RREG(uint8_t addr, uint8_t n);


#endif