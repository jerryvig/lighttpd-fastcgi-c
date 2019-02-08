// Compile with: gcc hello_fastcgi.c -o hello_fastcgi.fcgi -lfcgi -Wall -Wextra -pedantic -std=c11
#include <fcgi_stdio.h>
#include <stdlib.h>

int main (void) {
    while (FCGI_Accept() >= 0) {
        printf("Status: 200 OK\r\n");
        printf("Content-type: text/html\r\n\r\n");
        printf("<!doctype><html><body>Hola mundo from fastcgi!</body></html>\n");
    }
    return EXIT_SUCCESS;
}
