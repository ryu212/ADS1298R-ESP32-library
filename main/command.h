#ifndef COMMAND_H 
#define COMMAND_H

#include "SPIpro.h"
#include <inttypes.h>
void command_1_bytes(int8_t opcode);
void command_n_bytes(int8_t opcode, int8_t n, int8_t r);
int8_t* read_1_byte();
int8_t* read_n_byte(int n);
void write_n_bytes(int8_t* data, int n);
#endif