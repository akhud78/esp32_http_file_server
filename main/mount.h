#pragma once

#ifdef __cplusplus
extern "C" {
#endif

/* Function to initialize SPIFFS */
esp_err_t example_mount_storage(const char* base_path);

#ifdef __cplusplus
}
#endif

