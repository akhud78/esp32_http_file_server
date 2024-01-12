#include "esp_log.h"

#include "bar.h"

static const char *TAG = "bar";

int bar_add(int x, int y)
{
    ESP_LOGI(TAG, "%s", __func__); 
    
    return x + y;
}
