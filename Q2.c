//child process writes content. Parent process reads content.

#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

int main() {
    char *s, buf[1024];
    int fds[2];

    s = "My name is Supratim Sircar\n";

    pipe(fds);
    if (fork()) {
        printf("Inside Child process\n");
        write(fds[1], s, strlen(s));            //write() in child
        exit(0);
    }
    read(fds[0], buf, strlen(s));               //read() in parent

    printf("fds[0] = %d, fds[1] = %d\n", fds[0], fds[1]);
    write(1, buf, strlen(s));                   //display message from buffer

    return 0;
}