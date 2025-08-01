#include "DRDY_inter.h"
#include "MQTT_setup.h"
static void IRAM_ATTR drdy_isr_handler(void* arg)
{
    read_1(ECG_data);
    ESP_EARLY_LOGI(TAG, "DRDY interrupt triggered!");
    public(ECG_data);
}    
void init_drdy_interrupt()
{
    // Cấu hình chân DRDY làm input và có ngắt cạnh xuống
    gpio_config_t io_conf = {
        .intr_type = GPIO_INTR_NEGEDGE,
        .mode = GPIO_MODE_INPUT,
        .pin_bit_mask = 1ULL << DRDY_PIN,
        .pull_up_en = GPIO_PULLUP_ENABLE,
        .pull_down_en = GPIO_PULLDOWN_DISABLE,
    };
    gpio_config(&io_conf);
    gpio_install_isr_service(0);  // 0 = default interrupt flag
    gpio_isr_handler_add(DRDY_PIN, drdy_isr_handler, NULL);
}
