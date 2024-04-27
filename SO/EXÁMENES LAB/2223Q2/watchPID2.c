#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <signal.h>
#include <sys/wait.h>
#include <stdio.h>

struct estado_finalizacion {
    int exit_signal;
    int codigo;
};

int hmuertos = 0;
struct estado_finalizacion vfin[10];
int pids[10];

void Usage() {
    char buff[256];
    sprintf(buff, "Usage: ./watchPID2 interval count (PID).\n");
    write(1, buff, strlen(buff));
    sprintf(buff, "1 <= interval <= 5, 1 <= count <= 10\n");
    write(1, buff, strlen(buff));
    exit(0);
}

void error_y_exit(char* s) {
    perror(s);
    exit(EXIT_FAILURE);
}

void vacia() {}

void trata(int s) {
    int pid_muerto, st;
    while ((pid_muerto = waitpid(-1, &st, WNOHANG)) > 0) {
        int i = 0;
        while (pids[i] != pid_muerto) ++i;
        if (WIFEXITED(st)) {
            vfin[i].exit_signal = 0;
            vfin[i].codigo = WEXITSTATUS(st);
        }
        else {
            vfin[i].exit_signal = 1;
            vfin[i].codigo = WTERMSIG(st);
        }
        ++hmuertos;
    }
}

int main(int argc, char* argv[]) {
    char buff[256];
    int interval = atoi(argv[1]);
    int count = atoi(argv[2]);
    if (argc < 3 || argc > 4) Usage();
    if (interval < 1 || interval > 5) Usage();
    if (count < 1 || count > 10) Usage();

    sigset_t mask;
    sigemptyset(&mask);
    sigaddset(&mask, SIGUSR1);
    sigaddset(&mask, SIGUSR2);
    if (sigprocmask(SIG_BLOCK, &mask, 0) < 0) error_y_exit("sigprocmask call error");

    struct sigaction t;
    t.sa_handler = vacia;
    t.sa_flags = 0;
    sigemptyset(&t.sa_mask);
    if (sigaction(SIGALRM, &t, NULL) < 0) error_y_exit("sigaction call error");
    if (sigaction(SIGUSR1, &t, NULL) < 0) error_y_exit("sigaction call error");
    t.sa_handler = trata;
    if (sigaction(SIGCHLD, &t, NULL) < 0) error_y_exit("sigaction call error");

    int PID = getpid();
    if (argc == 4) PID = atoi(argv[3]);

    for (int i = 0; i < count; ++i) {
        pids[i] = fork();
        if (pids[i] == 0) {
            sigemptyset(&mask);
            sigsuspend(&mask);

            if (i != 0) {
                alarm(i*interval);
                sigfillset(&mask);
                sigdelset(&mask, SIGALRM);
                sigsuspend(&mask);
            }

            sprintf(buff, "INDEX: %d, PID: %d\n", i, getpid());
            write(1, buff, strlen(buff));
            sprintf(buff, "%d", PID);
            if (execlp("top", "top", "-b", "-n", "1", "-p", buff, (char*)NULL) < 0) error_y_exit("execlp call error");
        }
        else if (pids[i] < 0) error_y_exit("fork call error");
    }

    for (int i = 0; i < count; ++i) {
        if (i%2 != 0) {
            if (kill(pids[i], SIGUSR1) < 0) error_y_exit("kill call error");
        }
        else {
            if (kill(pids[i], SIGUSR2) < 0) error_y_exit("kill call error");
        }
    }
    
    while (hmuertos < count);
    for (int i = 0; i < count; ++i) {
        if (vfin[i].exit_signal == 0) {
            sprintf(buff, "El proceso con índice %d y PID %d ha acabado por exit con código %d\n", i, pids[i], vfin[i].codigo);
            write(1, buff, strlen(buff));
        }
        else {
            sprintf(buff, "El proceso con índice %d y PID %d ha acabado por signal %d\n", i, pids[i], vfin[i].codigo);
            write(1, buff, strlen(buff));
        }
    }
}