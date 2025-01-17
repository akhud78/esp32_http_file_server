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
- Wi-Fi Station Configuration
```
(Top) -> Component config -> Wi-Fi Station Configuration

(Keenetic-1234) Wi-Fi SSID
(qwerty42) Wi-Fi Password
(2) Maximum retry
(60) Connection Retry Period (s)
[*] Use static IP
(192.168.1.129) IP address
(192.168.1.1) Gateway (NEW)
(255.255.255.0) Mask (NEW)
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
- Use UART0 for console output
```
(Top) -> Component config -> ESP System Settings
    Channel for console output (Default: UART0)  --->
    Channel for console secondary output (No secondary console)  --->
```
- Save configuration and build the project
```
$ idf.py build
```
- Connect your device
- Flash onto the device
```
$ idf.py -p /dev/ttyUSB0 flash monitor
```
- To exit IDF monitor use the shortcut `Ctrl+]`.

## Permission denied error
```
PermissionError: [Errno 13] Permission denied: '/dev/ttyUSB0'
```
Fix this issue with the following commands:
```
sudo usermod -a -G tty $USER
sudo usermod -a -G dialout $USER
```