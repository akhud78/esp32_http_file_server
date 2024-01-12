# Tests

- [Home](../README.md)

---

## Building

```
$ cd ~/esp/esp32_http_file_server/test
$ . $HOME/esp/esp-idf-v5.1.1/export.sh
```
- Set the chip target to build
```
$ idf.py set-target esp32s3
```
- Change build [Configuration](config.md)
- [CMakeLists.txt](../test/CMakeLists.txt) - List of components to test
## Run tests
```
$ cd ~/esp/esp32_http_file_server/test/
$ rm build/CMakeCache.txt
$ idf.py -p /dev/ttyUSB0 -D TEST_COMPONENTS="bar" flash monitor
```