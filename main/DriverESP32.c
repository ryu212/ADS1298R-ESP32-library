#include <stdio.h>
#include "SPIpro.h"
#include "DRDY_inter.h"
#include "frontend_command.h"
#include "specialized_command.h"
#include "wifi_setup.h"
#include "mqtt_setup.h"


#define REST_PIN GPIO_NUM_25
#define STA_PIN GPIO_NUM_26
void app_main(void)
{
    //wifi_sta_init();
    //spi_master_init();
    //mqtt_app_start();
    
    spi_master_init();
    
    gpio_config_t io_conf = {
        .pin_bit_mask = (1ULL << REST_PIN),  // Chân cần cấu hình
        .mode = GPIO_MODE_OUTPUT,
        .pull_up_en = GPIO_PULLUP_ENABLE,
        .pull_down_en = GPIO_PULLDOWN_DISABLE,
        .intr_type = GPIO_INTR_DISABLE
    };
    gpio_config(&io_conf);

    gpio_config_t io_conf1 = {
        .pin_bit_mask = (1ULL << STA_PIN),  // Chân cần cấu hình
        .mode = GPIO_MODE_OUTPUT,
        .pull_up_en = GPIO_PULLUP_DISABLE,
        .pull_down_en = GPIO_PULLDOWN_DISABLE,
        .intr_type = GPIO_INTR_DISABLE
    };
    gpio_config(&io_conf1);

    gpio_set_level(REST_PIN, 0);
    vTaskDelay(1000 / portTICK_PERIOD_MS);
    gpio_set_level(REST_PIN, 1);
    reset(); // send SPI reset opcode if required by your device
    vTaskDelay(pdMS_TO_TICKS(1)); // 18 tCLK delay
    SDATAC();
    uint8_t temp = 0xC0;
    WREG(0x03, &temp, 1);
    temp = 0x86;
    WREG(0x01, &temp, 1);
    temp = 0x00;
    WREG(0x02, &temp, 1);
    temp = 0x01;
    WREG(0x05, &temp, 1);
    gpio_set_level(STA_PIN, 1);
    RDATAC();
    SDATAC();
    temp = 0x10; WREG(0x02, &temp, 1); // test signal config
    temp = 0x05; WREG(0x05, &temp, 1);  // test signal on channel
    RDATAC();
    //init_drdy_interrupt();
    int32_t ECGdata = 0;
    while(1)
    {
        read_1(&ECGdata, 1);
        printf("%ld\n",ECGdata);
        vTaskDelay(500 / portTICK_PERIOD_MS);
    }
}
