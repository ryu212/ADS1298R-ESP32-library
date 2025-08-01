#ifndef FRONTEND_COMMAND_H
#define FRONTEND_COMMAND_H
#include "specialized_command.h"

void read_1(uint8_t &data);
void read_reg(uint8_t addr);
void write_reg(uint8_t addr, uint8_t data);


#endif