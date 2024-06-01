#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <signal.h>
#include <errno.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>

void Usage() {
    char buff[256];
    sprintf(buff, "./espera_sig\n");
    write(1, buff, strlen(buff));
}

void error_y_exit(char *msg) {
    perror(msg);
    exit(EXIT_FAILURE);
}

void func(int s) {
    char buff[256];
    if (s == SIGINT) {
        sprintf(buff, "SIGINT RECIBIDO\n");
        write(1, buff, strlen(buff));
        exit(1);
    }
    else if (s == SIGUSR1) {
        sprintf(buff, "SIGUSR1 RECIBIDO\n");
        write(1, buff, strlen(buff));
        exit(2);
    }
    else {
        sprintf(buff, "SIGUSR2 RECIBIDO\n");
        write(1, buff, strlen(buff));
        exit(3);
    }
}

int main(int argc, char* argv[]) {
    if (argc != 1) Usage();
    
    sigset_t mask;
    sigemptyset(&mask);
    sigaddset(&mask, SIGINT);
    sigaddset(&mask, SIGUSR1);
    sigaddset(&mask, SIGUSR2);
    if (sigprocmask(SIG_BLOCK, &mask, NULL) < 0) error_y_exit("sigprocmask call error");

    struct sigaction t;
    t.sa_handler = func;
    t.sa_flags = 0;
    sigemptyset(&t.sa_mask);
    if (sigaction(SIGINT, &t, NULL) < 0) error_y_exit("sigaction call error");
    if (sigaction(SIGUSR1, &t, NULL) < 0) error_y_exit("sigaction call error");
    if (sigaction(SIGUSR2, &t, NULL) < 0) error_y_exit("sigaction call error");

    sigfillset(&mask);
    sigdelset(&mask, SIGINT);
    sigdelset(&mask, SIGUSR1);
    sigdelset(&mask, SIGUSR2);
    sigsuspend(&mask);
}