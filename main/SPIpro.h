#ifndef SPI_PRO_H
#define SPI_PRO_H
#include "driver/spi_master.h"
#include "driver/gpio.h"
#include "esp_log.h"
#include <inttypes.h>

#define TAG "SPI_MASTER"
#define PIN_NUM_MISO 19
#define PIN_NUM_MOSI 23
#define PIN_NUM_CLK  18
#define PIN_NUM_CS   5
spi_device_handle_t spi;

void spi_master_init(void);
int8_t* spi_sent_receive(int8_t* send_data, int send_bytes, int receive_bytes);
#endif
