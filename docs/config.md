# Configuration

- [Home](../README.md)

---
## Main
- Open the project configuration menu
```
$ cd ~/esp/esp32_http_file_server
$ idf.py menuconfig
```
- Project configuration - [Kconfig.projbuild](../main/Kconfig.projbuild)

## Common

- Project configuration
```
(Top) -> Project configuration

(esp32-fs) mDNS hostname
[*] Send connection close header from request handlers
```
- Set HTTP Request Header Length
```
(Top) -> Component config -> HTTP Server

(1024) Max HTTP Request Header Length
(1024) Max HTTP URI Length
```
- Wi-Fi Station Configuration
```
(Top) -> Component config -> Wi-Fi Station Configuration

(Keenetic-1234) Wi-Fi SSID
(qwerty42) Wi-Fi Password
(2) Maximum retry
(60) Connection Retry Period (s)
[ ] Use static IP
```
- Using with [esp32_nat_router](https://github.com/akhud78/esp32_nat_router)
```
(s3hotspot) Wi-Fi SSID
(12345678) Wi-Fi Password
(2) Maximum retry
(60) Connection Retry Period (s)
[*] Use static IP
(192.168.4.100) IP address
(192.168.4.1) Gateway
(255.255.255.0) Mask
```
- Set Max WiFi TX power :boom:
```
(Top)-> Component config -> PHY
(14) Max WiFi TX power (dBm)
```
- Use `USB Serial` for console output
```
(Top) -> Component config -> ESP System Settings
    Channel for console output (USB Serial/JTAG Controller)  --->
```
- Save configuration and build the project
```
$ idf.py build
```
- Connect your device
- Flash onto the device
```
$ idf.py -p /dev/ttyACM0 erase-flash
$ idf.py -p /dev/ttyACM0 flash monitor
```
- To exit IDF monitor use the shortcut `Ctrl+]`.
