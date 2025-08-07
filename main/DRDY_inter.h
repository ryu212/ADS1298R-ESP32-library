#ifndef DRDY_INTER_H
#define DRDY_INTER_H
#include "driver/gpio.h"
#include "esp_intr_alloc.h"
#include "esp_log.h"

#define DRDY_PIN  GPIO_NUM_4
#define CHANNEL 1

extern int32_t ECG_data;
//atic const char *TAG = "DRDY";
//static void IRAM_ATTR drdy_isr_handler(void* arg);

void init_drdy_interrupt();





#endif 