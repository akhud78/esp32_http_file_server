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

## Test
```
$ cd ~/esp/esp32_http_file_server/test
$ idf.py menuconfig
```
- Disable watchdog

```
(Top) -> Component config -> ESP System Settings
[ ] Interrupt watchdog
[ ] Initialize Task Watchdog Timer on startup

(Top) -> Component config -> Unity unit testing library
[*] Colorize test output
```
## Common
- Enable SPI RAM
```
(Top) -> Component config -> ESP PSRAM -> 
         Support for external, SPI-connected RAM -> SPI RAM config

    Mode (QUAD/OCT) of SPI RAM chip in use (Quad Mode PSRAM)  --->
```
- Use Custom partition table
- [partitions.csv](../partitions.csv)
```
(Top) -> Partition Table
    Partition Table (Custom partition table CSV)  --->
(partitions.csv) Custom partition CSV file
(0x8000) Offset of partition table
[*] Generate an MD5 checksum for the partition table
```
- Set Flash size  to 8 MB
```
(Top) -> Serial flasher config
    Flash size (8 MB)  --->
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