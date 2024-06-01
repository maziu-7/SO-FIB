#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <signal.h>
#include <errno.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>

void Usage() {
    char buff[256];
    sprintf(buff, "./lee_signals filename\n");
    write(1, buff, strlen(buff));
    exit(0);
}

void error_y_exit(char *msg) {
    perror(msg);
    exit(EXIT_FAILURE);
}

void func() {}

int main(int argc, char* argv[]) {
    if (argc != 2) Usage();
    char buff[256];

    struct sigaction t;
    t.sa_handler = func;
    t.sa_flags = 0;
    sigemptyset(&t.sa_mask);
    if (sigaction(SIGALRM, &t, NULL) < 0) error_y_exit("sigaction call error");

    int fd = open(argv[1], O_WRONLY);
    if (fd < 0) error_y_exit("open call error");

    int fd1 = open("mis_eventos", O_WRONLY);
    if (fd1 < 0) error_y_exit("open call error");

    int fd2 = open("exit_status.int", O_RDONLY);
    if (fd2 < 0) error_y_exit("open call error");

    int pid,signal;
    while (read(fd2, &pid, sizeof(int)) > 0) {
        read(fd2, &signal, sizeof(int));

        write(fd, &pid, sizeof(int));
        write(fd, &signal, sizeof(int));

        alarm(5);

        sigset_t mask;
        sigfillset(&mask);
        sigdelset(&mask, SIGALRM);
        sigsuspend(&mask);

        int pid2,signal2;
        int i = 0;
        while (read(fd2, &pid2, sizeof(int)) > 0) {
            read(fd2, &signal2, sizeof(int));
            sprintf(buff, "El proceso %d con PID %d ha terminado con estado %d", i, pid2, signal2);
            write(1, buff, strlen(buff));
            ++i;
        }
    }
}