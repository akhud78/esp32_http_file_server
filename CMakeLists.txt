# For more information about build system see
# https://docs.espressif.com/projects/esp-idf/en/v5.0.2/esp32/api-guides/build-system.html
cmake_minimum_required(VERSION 3.16)
include($ENV{IDF_PATH}/tools/cmake/project.cmake)
project(esp32_http_file_server)

idf_build_set_property(COMPILE_OPTIONS "-Wno-error=format=" APPEND)
idf_build_set_property(COMPILE_OPTIONS "-Wno-format" APPEND)
