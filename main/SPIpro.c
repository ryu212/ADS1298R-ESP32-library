#include "SPIpro.h"

void spi_master_init(void)
{
    spi_bus_config_t buscfg = {
        .miso_io_num = PIN_NUM_MISO,
        .mosi_io_num = PIN_NUM_MOSI,
        .sclk_io_num = PIN_NUM_CLK,
        .quadwp_io_num = -1,
        .quadhd_io_num = -1,
        .max_transfer_sz = 216 
    };
    esp_err_t ret = spi_bus_initialize(HSPI_HOST, &buscfg, SPI_DMA_CH_AUTO);
    ESP_ERROR_CHECK(ret);
    spi_device_interface_config_t devcfg = {
        .clock_speed_hz = 1000000,
        .mode = 0,
        .spics_io_num = GPIO_NUM_5,
        .queue_size = 1,
    };
    spi_bus_add_device(HSPI_HOST, &devcfg, &spi);
}

uint8_t* spi_sent_receive(uint8_t* send_data, int send_bytes, int receive_bytes)
{
    uint8_t* receive_buffer = NULL;
    if (receive_bytes > 0) {
        receive_buffer = malloc(receive_bytes);
        if (!receive_buffer) {
            ESP_LOGE("SPI", "Failed to allocate memory for receive_buffer");
            return NULL;
        }
    }

    spi_transaction_t t = {
        .flags = SPI_DEVICE_HALFDUPLEX,
        .length = send_bytes * 8,     // Gửi bao nhiêu bit
        .rxlength = receive_bytes * 8, // Nhận bao nhiêu bit
        .tx_buffer = send_data,
        .rx_buffer = receive_buffer,
    };

    esp_err_t ret = spi_device_transmit(spi, &t);
    ESP_ERROR_CHECK(ret);

    if (receive_bytes && ret == ESP_OK) {
        ESP_LOGI("SPI", "Received:");
        for (int i = 0; i < receive_bytes; i++) {
            printf("0x%02X ", receive_buffer[i]);
        }
        printf("\n");
    }

    return receive_buffer;  // có thể NULL nếu receive_bytes == 0
}









