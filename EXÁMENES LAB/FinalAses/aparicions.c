#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/wait.h>

void Usage() {
    char buff[256];
    sprintf(buff, "Usage: ./aparicions textfile char\n");
    write(1, buff, strlen(buff));
    exit(0);
}

void error_y_exit(char *s) {
    perror(s);
    exit(EXIT_FAILURE);
}

int main(int argc, char* argv[]) {
    char buff[256];
    if (argc != 3) Usage();
    char c = argv[2][0];
    int fd = open(argv[1], O_RDONLY);
    if (fd < 0) error_y_exit("open call error");

    char s;
    int i = 0;
    int trobat = 0;
    while (read(fd, &s, sizeof(char)) > 0) {
        if (s == c) {
            sprintf(buff, "%d ", i);
            write(1, buff, strlen(buff));
            trobat = 1;
        }
        ++i;
    }
    if (!trobat) {
        sprintf(buff, "-1");
        write(1, buff, strlen(buff));
    }
    sprintf(buff, "\n");
    write(1, buff, strlen(buff));
}