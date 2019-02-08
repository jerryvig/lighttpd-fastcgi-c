This is a minimal example for how to build FastCGI programs written in C with gcc, and run them with the lighttpd ("lighty") general purpose web server.

This example was built with lighttpd-1.4.x (<https://github.com/lighttpd/lighttpd1.4>). To run this example you will need to ensure that lightttpd's `mod_fastcgi` is enabled. It is enabled by default with the standard lighttpd distribution. You'll also need the FastCGI developer kit fcgi2 (<https://github.com/FastCGI-Archives/fcgi2>) installed on your system.

To build and install FastCGI developer kit do the following from the command line:

```
$ git clone https://github.com/FastCGI-Archives/fcgi2
$ cd fcgi2/
$ ./autogen.sh
$ ./configure
$ make
$ sudo make install
```
After installing the FastCGI developer kit (fcgi2), you should then be able to build the C application with:

```
$ gcc hello_fastcgi.c -o hello_fastcgi.fcgi -lfcgi -O3 -Wall -Wextra -pedantic -std=c11
```
The key configuration of the FastCGI server is at the end of this `lightttpd.conf` file. The line `"bin-path" => "hello_fastcgi.fcgi"` tells lighttpd to launch a persistent background FastCGI process for the `hello_fastcgi.fcgi` application. The line `"socket" => "/tmp/hello_fastcgi.sock"` tells lighttpd to communicate with background proc(s) via unix socket(s). lighttpd can also communicate with FastCGI apps via TCP. See the lighttpd modfastcgi documentation at <https://redmine.lighttpd.net/projects/lighttpd/wiki/docs_modfastcgi> for more examples and further explanation.
```
fastcgi.debug = 1
fastcgi.server = (
  "/hello" => ((
    "bin-path" => "hello_fastcgi.fcgi",
    "socket" => "/tmp/hello_fastcgi.sock",
    "check-local" => "disable",
    "max-procs" => 2,
  ))
)
```
After building the C application with gcc, you should now be able to run the `hello_fastcgi.fcgi` FastCGI application with lighttpd as the http web front end of your application, and navigate to <http://localhost:8080/hello> to see the output of your FastCGI application.
```
$ lighttpd -D -f lighttpd.conf
```
