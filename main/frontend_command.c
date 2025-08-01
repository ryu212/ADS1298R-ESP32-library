#include "frontend_command.h"

void read_1(uint32_t &data, int channel)
{
    uint8_t* data =  RDATA();
    data = data[3*channel] << 16 | data[3*channel + 1] << 8 | data[3*channel + 2];
}

void read_reg(uint8_t addr)
{
    uint8_t output = *RREG(addr, 1);
    printf("output %u", output);
}
void write_reg(uint8_t addr, uint8_t data)
{
    WREG(addr, &data, 1);
}
