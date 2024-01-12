# esp32_http_file_server
Simple HTTP File Server Example

## Requirements
- Ubuntu 20.04 LTS
- [ESP-IDF v5.1.1](https://docs.espressif.com/projects/esp-idf/en/v5.1.1/esp32s3/index.html)
- [ESP32-S3-DevKitC-1](https://docs.espressif.com/projects/esp-idf/en/latest/esp32s3/hw-reference/esp32s3/user-guide-devkitc-1.html)

## Links

- [Logging library](https://docs.espressif.com/projects/esp-idf/en/v5.1.1/esp32s3/api-reference/system/log.html)
- [HTTP Server](https://docs.espressif.com/projects/esp-idf/en/v5.1.1/esp32s3/api-reference/protocols/esp_http_server.html)
- [Simple HTTP File Server Example](https://github.com/espressif/esp-idf/tree/master/examples/protocols/http_server/file_serving)
- [mDNS Service](https://docs.espressif.com/projects/esp-protocols/mdns/docs/latest/en/index.html)

## Building
- Get ESP-IDF
```
$ mkdir -p ~/esp
$ cd ~/esp
$ git clone -b v5.1.1 --recursive https://github.com/espressif/esp-idf.git esp-idf-v5.1.1
$ cd esp-idf-v5.1.1/
$ ./install.sh
```
- Checking
```
$ . $HOME/esp/esp-idf-v5.1.1/export.sh
```
- Clone and setup [project](https://github.com/akhud78/esp32_http_file_server)
```
$ cd ~/esp
$ git clone https://github.com/akhud78/esp32_http_file_server
$ cd ~/esp/esp32_http_file_server
$ git submodule update --init --recursive
```
- Set the chip target to build
```
$ idf.py set-target esp32s3
```
- Add [mDNS Service](https://components.espressif.com/components/espressif/mdns) component
```
$ idf.py add-dependency mdns^1.2.3
```
- Change build [Configuration](docs/config.md)

## Run
- Connect development board to your computer and run
```
$ cd ~/esp/esp32_http_file_server
$ idf.py -p /dev/ttyUSB0 flash monitor
```
- [esp32-fs.local](http://esp32-fs.local/)
- To exit IDF monitor use the shortcut `Ctrl+]`.

## Usage
- [Tests](docs/tests.md)
