#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <signal.h>
#include <sys/wait.h>
#include <stdio.h>

void Usage() {
    char buff[256];
    sprintf(buff, "Usage: ./watchPID interval count (PID).\n");
    write(1, buff, strlen(buff));
    sprintf(buff, "1 <= interval <= 5, 1 <= count <= 10\n");
    write(1, buff, strlen(buff));
    exit(0);
}

void error_y_exit(char* s) {
    perror(s);
    exit(EXIT_FAILURE);
}

void trata_alarma() {}

int main(int argc, char* argv[]) {
    char buff[256];
    int interval = atoi(argv[1]);
    int count = atoi(argv[2]);
    if (argc <= 2 || argc >= 5) Usage();
    if (interval < 1 || interval > 5) Usage();
    if (count < 1 || count > 10) Usage();

    sigset_t mask;
    sigemptyset(&mask);
    sigaddset(&mask, SIGALRM);
    if (sigprocmask(SIG_BLOCK, &mask, 0) < 0) error_y_exit("sigprocmask call error");

    struct sigaction t;
    t.sa_handler = trata_alarma;
    t.sa_flags = 0;
    sigemptyset(&t.sa_mask);
    if (sigaction(SIGALRM, &t, NULL) < 0) error_y_exit("sigaction call error");

    int PID = getpid();
    if (argc == 4) PID = atoi(argv[3]);

    sigfillset(&mask);
    sigdelset(&mask, SIGALRM);
    for (int i = 0; i < count; ++i) {
        int h = fork();
        if (h == 0) {
            if (i != 0) {
                alarm(i*interval);
                sigsuspend(&mask);
            }

            sprintf(buff, "INDEX: %d, PID: %d", i, getpid());
            write(1, buff, strlen(buff));
            sprintf(buff, "%d", PID);
            if (execlp("top", "top", "-b", "-n", "1", "-p", buff, (char*)NULL) < 0) error_y_exit("execlp call error");
        }
        else if (h < 0) error_y_exit("fork call error");
    }
    while(waitpid(-1, NULL, 0) > 0);
}