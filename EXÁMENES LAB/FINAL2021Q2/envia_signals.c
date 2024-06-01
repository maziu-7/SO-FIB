#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <signal.h>
#include <errno.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>

void Usage() {
    char buff[256];
    sprintf(buff, "./envia_signals\n");
    write(1, buff, strlen(buff));
}

void error_y_exit(char *msg) {
    perror(msg);
    exit(EXIT_FAILURE);
}

int main(int argc, char* argv[]) {
    if (argc != 1) Usage();
    char buff[256];

    int fd = open("mis_eventos", O_RDONLY);

    int pid,signal;
    while (read(fd, &pid, sizeof(int)) > 0) {
        read(fd, &signal, sizeof(int));
        if (kill(pid, signal) < 0) error_y_exit("kill call error");
        sprintf(buff, "ENVIADO SIGNAL %d A HIJO %d\n", signal, pid);
        write(1, buff, strlen(buff));
    }
}