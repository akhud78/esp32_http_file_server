#include "esp_log.h"

#include "foo.h"

static const char *TAG = "foo";

int foo_init(void)
{
    ESP_LOGI(TAG, "%s", __func__); 
    
    return 0;
}
