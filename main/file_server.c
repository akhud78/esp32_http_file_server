// https://github.com/espressif/esp-idf/blob/master/examples/protocols/http_server/file_serving/main/file_server.c
#include <stdio.h>
#include <string.h>
#include <sys/param.h>
#include <sys/unistd.h>
#include <sys/stat.h>
#include <dirent.h>

#include "esp_err.h"
#include "esp_log.h"

//#include "esp_vfs.h"
//#include "esp_spiffs.h"
#include "esp_http_server.h"

static const char *TAG = "file_server";


esp_err_t file_server_start(const char *base_path)
{
    ESP_LOGI(TAG, "%s", __func__); 
    esp_err_t err = ESP_OK;

    
    // ...
    
    return err;
}
