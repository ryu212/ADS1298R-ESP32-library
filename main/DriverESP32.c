#include <stdio.h>
#include "SPIpro.h"
#include "DRDY_inter.h"
#include "frontend_command.h"
#include "specialized_command.h"
#include "wifi_setup.h"
#include "mqtt_setup.h"
void app_main(void)
{
    //wifi_sta_init();
    //spi_master_init();
    //mqtt_app_start();
    
    spi_master_init();
    start();
    init_drdy_interrupt();
}
