#include "specialized_command.h"

void wakeup()  { command_1_bytes(0x02); }
void standby() { command_1_bytes(0x04); }
void reset()   { command_1_bytes(0x06); }
void start()   { command_1_bytes(0x08); }
void stop()    { command_1_bytes(0x0A); }
void RDATAC()  { command_1_bytes(0x10); }
void SDATAC()  { command_1_bytes(0x11); }
uint8_t* RDATA()
{
    command_1_bytes(0x12);
    return read_n_byte(216);
}
void WREG(uint8_t addr, uint8_t* data, uint8_t n)
{
    uint8_t cmd[2] = { 0x40 | addr, n - 1 };
    spi_sent_receive(cmd, 2, 0);
    write_n_bytes(data, n);
}
uint8_t* RREG(uint8_t addr, uint8_t n)
{
    uint8_t cmd[2] = { 0x20 | addr, n - 1 };
    spi_sent_receive(cmd, 2, 0);
    return read_n_byte(n);
}
