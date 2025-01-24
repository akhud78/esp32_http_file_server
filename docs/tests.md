# Tests

- [Home](../README.md)

---
## Setup
- Run [httpbin.org](http://httpbin.org) locally
```
$ docker run -p 8000:80 kennethreitz/httpbin
```
- Check [localhost:8000](http://localhost:8000)  httpbin
```
$ SOCK=localhost:8000
```
## cURL
### GET
- GET `html` from [localhost:8000](http://localhost:8000)
- <b>Content-Length: 3741</b>
```
$ curl -v $SOCK/html
*   Trying 127.0.0.1:8000...
* Connected to localhost (127.0.0.1) port 8000 (#0)
> GET /html HTTP/1.1
> Host: localhost:8000
> User-Agent: curl/7.81.0
> Accept: */*
> 
* Mark bundle as not supporting multiuse
< HTTP/1.1 200 OK
< Date: Fri, 24 Jan 2025 10:15:17 GMT
< Content-Type: text/html; charset=utf-8
< Content-Length: 3741           <-- !!!
< Connection: keep-alive
< Server: gunicorn/19.9.0
< Access-Control-Allow-Origin: *
< Access-Control-Allow-Credentials: true
< 
<!DOCTYPE html>
<html>
  <head>
  </head>
  <body>
      <h1>Herman Melville - Moby-Dick</h1>
...
  </body>
* Connection #0 to host httpbin.org left intact
```
### Dynamic data
- Check [ESP32 File Server](http://esp32-fs.local/)
- GET `mobydick.html` from `esp32-fs.local`
- <b>Transfer-Encoding: chunked</b>
```
$ curl -v http://esp32-fs.local/mobydick.html
*   Trying 192.168.1.145:80...
* Connected to esp32-fs.local (192.168.1.145) port 80 (#0)
> GET /mobydick.html HTTP/1.1
> Host: esp32-fs.local
> User-Agent: curl/7.81.0
> Accept: */*
> 
* Mark bundle as not supporting multiuse
< HTTP/1.1 200 OK
< Content-Type: text/html
< Transfer-Encoding: chunked     <-- !!!
< 
<!DOCTYPE html>
<html>
  <head>
  </head>
  <body>
      <h1>Herman Melville - Moby-Dick</h1>
...
  </body>
</html>
* Connection #0 to host esp32-fs.local left intact
```
- GET `stream` JSON responses from `localhost:8000`
```
$ curl -v $SOCK/stream/2
*   Trying 127.0.0.1:8000...
* Connected to localhost (127.0.0.1) port 8000 (#0)
> GET /stream/2 HTTP/1.1
> Host: localhost:8000
> User-Agent: curl/7.81.0
> Accept: */*
> 
* Mark bundle as not supporting multiuse
< HTTP/1.1 200 OK
< Server: gunicorn/19.9.0
< Date: Fri, 24 Jan 2025 11:05:30 GMT
< Connection: keep-alive
< Transfer-Encoding: chunked  <-- !!!
< Content-Type: application/json
< Access-Control-Allow-Origin: *
< Access-Control-Allow-Credentials: true
< 
{"url": "http://localhost:8000/stream/2", "args": {}, "headers":
  {"Host": "localhost:8000", "User-Agent": "curl/7.81.0", "Accept": "*/*"}, "origin": "172.17.0.1", "id": 0}
{"url": "http://localhost:8000/stream/2", "args": {}, "headers":
  {"Host": "localhost:8000", "User-Agent": "curl/7.81.0", "Accept": "*/*"}, "origin": "172.17.0.1", "id": 1}
* Connection #0 to host localhost left intact
```