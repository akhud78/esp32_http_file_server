# esp32_template
ESP-IDF template app

## Requirements
- Ubuntu 20.04 LTS
- [ESP-IDF v5.1.1](https://docs.espressif.com/projects/esp-idf/en/v5.1.1/esp32s3/index.html)
- [ESP32-S3-DevKitC-1](https://docs.espressif.com/projects/esp-idf/en/latest/esp32s3/hw-reference/esp32s3/user-guide-devkitc-1.html)

## Links

- [Logging library](https://docs.espressif.com/projects/esp-idf/en/v5.1.1/esp32s3/api-reference/system/log.html)

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
- Clone and setup [project](https://github.com/akhud78/esp32_template)
```
$ cd ~/esp
$ git clone https://github.com/akhud78/esp32_template
$ cd ~/esp/esp32_template
$ git submodule update --init --recursive
```
- Set the chip target to build
```
$ idf.py set-target esp32s3
```
- Change build [Configuration](docs/config.md)

## Run
- Connect development board to your computer and run
```
$ cd ~/esp/esp32_template
$ idf.py -p /dev/ttyUSB0 flash monitor
```
- To exit IDF monitor use the shortcut `Ctrl+]`.

## Usage
- [Tests](docs/tests.md)