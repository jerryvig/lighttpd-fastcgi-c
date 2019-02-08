This is a minimal example for how to build FastCGI programs written in C with gcc, and run them with the lighttpd ("lighty") general purpose web server.

This example was built with lighttpd-1.4.x (<https://github.com/lighttpd/lighttpd1.4>). In addition to lighttpd, you will also need the FastCGI developer kit fcgi2 (<https://github.com/FastCGI-Archives/fcgi2>) installed on your system.

To build and install FastCGI developer kit do the following from the command line:

```
$ git clone https://github.com/FastCGI-Archives/fcgi2
```
