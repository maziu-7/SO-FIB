#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <sys/wait.h>
#include <signal.h>
#include <stdlib.h>

int alarma_recibida = 0;

void Usage() {
    char buff[256];
    sprintf(buff, "Usage: ./poema N S\n");
    write(1, buff, strlen(buff));
    exit(0);
}

void error_y_exit(char* msg) {
    perror(msg);
    exit(EXIT_FAILURE);
}

void trata_alarma() {
    alarma_recibida = 1;
}

void trata_sigusr1() {
    
}

int main(int argc, char* argv[]) {
    if (argc != 3) Usage();

    sigset_t mask;
    sigemptyset(&mask);
    sigaddset(&mask, SIGUSR1);
    sigprocmask(SIG_BLOCK, &mask, NULL);

    struct sigaction t;
    sigfillset(&t.sa_mask);
    t.sa_flags = SA_RESTART;
    t.sa_handler = trata_alarma;
    if (sigaction(SIGALRM, &t, NULL) < 0) error_y_exit("sigaction call error");
    t.sa_handler = trata_sigusr1;
    if (sigaction(SIGUSR1, &t, NULL) < 0) error_y_exit("sigaction call error");

    char buff[256];
    int N = atoi(argv[1]);
    int pids[N];
    int S = atoi(argv[2]);

    sigfillset(&mask);
    sigdelset(&mask, SIGUSR1);
    for (int i = 0; i < N; ++i) {
        pids[i] = fork();
        if (pids[i] == 0) {
            alarm(S);
            while (alarma_recibida == 0);
            alarma_recibida = 0;
            kill(pids[i], SIGUSR1);
            sigsuspend(&mask);
            sprintf(buff, "texto_f%d.txt", i+1);
            if (execlp("cat", "cat", buff, (char*)NULL) < 0) error_y_exit("execlp call error");
        }
        else if (pids[i] < 0) error_y_exit("fork call error");
        waitpid(pids[i], NULL, 0);
    }
}