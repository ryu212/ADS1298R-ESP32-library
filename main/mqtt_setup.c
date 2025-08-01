#include "mqtt_setup.h"
static void mqtt_event_handler(void *handler_args, esp_event_base_t base,
    int32_t event_id, void *event_data)
{
esp_mqtt_event_handle_t event = event_data;

switch ((esp_mqtt_event_id_t)event_id) {
case MQTT_EVENT_CONNECTED:
ESP_LOGI(TAG, "MQTT connected");
esp_mqtt_client_publish(client, "/esp32/data", "hello", 0, 1, 0);
break;

case MQTT_EVENT_DISCONNECTED:
ESP_LOGW(TAG, "MQTT disconnected");
break;

default:
break;
}
}

void mqtt_app_start(void)
{
const esp_mqtt_client_config_t mqtt_cfg = {
.uri = YOUR_URI, 
};

client = esp_mqtt_client_init(&mqtt_cfg);
esp_mqtt_client_register_event(client, ESP_EVENT_ANY_ID, mqtt_event_handler, NULL);
esp_mqtt_client_start(client);
}

void public(int32_t data)
{
    char payload[64];
    snprintf(payload, sizeof(payload), "{\"sensor\": %u}", data);
    esp_mqtt_client_publish(client, YOUR_TOPIC, payload, 0, 1, 0);
}