#include <stdio.h>
#include <string.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

#include "esp_log.h"
#include "driver/gpio.h"

#include "mdns.h"

#include "foo.h"
#include "bar.h"
#include "app.h"
#include "file_server.h"
#include "wifi.h"

#define BLINK_GPIO          (CONFIG_BLINK_GPIO)
#define MDNS_HOSTNAME       "esp32-fs"        //(CONFIG_MDNS_HOSTNAME)

static const char *TAG = "app";

void initialise_mdns(void)
{
    //initialize mDNS
    ESP_ERROR_CHECK( mdns_init() );
    //set mDNS hostname (required if you want to advertise services)
    ESP_ERROR_CHECK( mdns_hostname_set(MDNS_HOSTNAME) );
    ESP_LOGI(TAG, "mdns hostname set to: [%s]", MDNS_HOSTNAME);

#if 0
    //set default mDNS instance name
    ESP_ERROR_CHECK( mdns_instance_name_set("ESP32 with mDNS") );
#endif
}

void app(void)
{
    ESP_LOGI(TAG, "%s", __func__); 
    
    gpio_reset_pin(BLINK_GPIO);
    gpio_set_direction(BLINK_GPIO, GPIO_MODE_OUTPUT);
    gpio_set_level(BLINK_GPIO, 1);
    
    vTaskDelay(pdMS_TO_TICKS(1000));
    gpio_set_level(BLINK_GPIO, 0);
    
    foo_init();
    bar_add(1, 2);
    
    ESP_ERROR_CHECK( wifi_sta_start(WIFI_STA_SSID, WIFI_STA_PASS, NULL, 0, 0) );
    initialise_mdns();
    
    /* Initialize file storage */
    // ...
    const char* base_path = "/data";
    
    /* Start the file server */
    ESP_ERROR_CHECK( file_server_start(base_path) );
    ESP_LOGI(TAG, "File server started");
    
}
