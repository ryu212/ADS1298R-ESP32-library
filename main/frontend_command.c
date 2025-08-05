#include "frontend_command.h"
void read_1(int32_t *data, int channel)
{
    uint8_t* ECGdata = RDATA();  
    *data = ((int32_t)ECGdata[3 * channel] << 16) |
            ((int32_t)ECGdata[3 * channel + 1] << 8) |
            ((int32_t)ECGdata[3 * channel + 2]);
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
