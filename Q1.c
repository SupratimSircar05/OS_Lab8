//inter-process communication

#include <stdio.h>
#include <string.h>
#include <unistd.h>

int main() {
    char *s, buf[1024];
    int fds[2];

    s = "My name is Supratim Sircar\n";

    pipe(fds);
    write(fds[1], s, strlen(s));
    read(fds[0], buf, strlen(s));

    printf("fds[0] = %d, fds[1] = %d\n", fds[0], fds[1]);
    write(1, buf, strlen(s));

    return 0;
}
