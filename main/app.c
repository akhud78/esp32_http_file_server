#include <stdio.h>
#include <string.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

#include "esp_log.h"
#include "driver/gpio.h"

#include "foo.h"
#include "bar.h"
#include "app.h"

#define BLINK_GPIO      (CONFIG_BLINK_GPIO)

static const char *TAG = "app";

void app(void)
{
    ESP_LOGW(TAG, "%s", __func__); 
    
    gpio_reset_pin(BLINK_GPIO);
    gpio_set_direction(BLINK_GPIO, GPIO_MODE_OUTPUT);
    gpio_set_level(BLINK_GPIO, 1);
    
    vTaskDelay(pdMS_TO_TICKS(1000));
    gpio_set_level(BLINK_GPIO, 0);
    
    foo_init();
    bar_add(1, 2);
}
