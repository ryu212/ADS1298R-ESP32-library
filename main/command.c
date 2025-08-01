#include "command.h"

// Gửi 1 byte lệnh (opcode)
void command_1_bytes(int8_t opcode)
{
    uint8_t data[1] = { opcode };
    spi_sent_receive(data, 1, 0);  // chỉ gửi, không nhận
}

// Gửi opcode + số lượng byte, như WREG, RREG,...
void command_n_bytes(int8_t opcode, int8_t n, int8_t r)
{
    uint8_t data[2] = { opcode + r, n };
    spi_sent_receive(data, 2, 0);  // gửi 2 byte
}

// Đọc 1 byte (ví dụ sau khi gửi RDATA)
uint8_t* read_1_byte()
{
    // chỉ nhận 1 byte, không cần gửi gì
    return spi_sent_receive(NULL, 0, 1);
}

// Đọc nhiều byte
uint8_t* read_n_byte(int n)
{
    if (n <= 0) return NULL;
    return spi_sent_receive(NULL, 0, n);
}

// Gửi nhiều byte (không nhận lại gì)
void write_n_bytes(uint8_t* data, int n)
{
    if (data == NULL || n <= 0) return;
    spi_sent_receive(data, n, 0);
}
