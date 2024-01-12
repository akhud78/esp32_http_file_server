#include <stdio.h>
#include <string.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

#include "esp_log.h"

#include "app.h"

extern "C" void app_main(void) 
{
    ESP_LOGI("","%s Build: %s @ %s", __func__ , __DATE__, __TIME__);
    
    app();
    
    while (1) {
        vTaskDelay(200 / portTICK_PERIOD_MS);
    }
}




