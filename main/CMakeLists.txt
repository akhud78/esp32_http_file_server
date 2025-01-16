idf_component_register(SRC_DIRS "."
                    REQUIRES driver foo bar esp_http_server vfs wifi mdns spiffs fatfs esp_timer
                    INCLUDE_DIRS "."
                    EMBED_FILES "favicon.ico" "upload_script.html")
                    
