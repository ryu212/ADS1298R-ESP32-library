#ifndef MQTT_SETUP_H
#define MQTT_SETUP_H

#include "mqtt_client.h"
#include "esp_log.h"
#define YOUR_URI "mqtt....." // config your MQTT URI here
#define YOUR_TOPIC "/esp32/data"
static const char *TAG = "MQTT";

esp_mqtt_client_handle_t client = NULL;

static void mqtt_event_handler(void *handler_args, esp_event_base_t base, int32_t event_id, void *event_data);
void mqtt_app_start(void);
void public(int32_t data);



#endif