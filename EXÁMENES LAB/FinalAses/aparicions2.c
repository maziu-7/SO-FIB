#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>

int alarma_recibida = 0;

void Usage() {
    char buff[256];
    sprintf(buff, "Usage: ./aparicions2 filename N S\n");
    write(1, buff, strlen(buff));
    exit(0);
}

void error_y_exit(char *s) {
    perror(s);
    exit(EXIT_FAILURE);
}

void func(int s) {
    char buff[256];
    if (s == SIGALRM) {
        sprintf(buff, "PARE (%d): ALARMA REBUDA\n", getpid());
        write(1, buff, strlen(buff));
        alarma_recibida = 1;
    }
    else if (s == SIGUSR1) {
        sprintf(buff, "FILL (%d): SIGUSR1 REBUT\n", getpid());
        write(1, buff, strlen(buff));
    }
}

int main(int argc, char* argv[]) {
    char buff[256];
    if (argc != 4) Usage();

    int N = atoi(argv[2]);
    int S = atoi(argv[3]);
    if (N <= 0) Usage();
    if (S <= 0) Usage();

    //bloqueamos sigusr1 para el sigsuspend
    sigset_t mask;
    sigemptyset(&mask);
    sigaddset(&mask, SIGUSR1);
    if (sigprocmask(SIG_BLOCK, &mask, NULL) < 0) error_y_exit("sigprocmask call error");

    //reprogramamos sigalrm para el padre
    struct sigaction ta;
    ta.sa_handler = func;
    ta.sa_flags = 0;
    sigemptyset(&ta.sa_mask);
    if (sigaction(SIGALRM, &ta, NULL) < 0) error_y_exit("sigaction call error");

    char c;
    int pids[N];
    for (int i = 0; i < N; ++i) {
        read(0, &c, sizeof(char));
        pids[i] = fork();
        if (pids[i] == 0) {
            //reprogramamos sigusr1
            struct sigaction ta;
            ta.sa_handler = func;
            ta.sa_flags = 0;
            sigemptyset(&ta.sa_mask);
            if (sigaction(SIGUSR1, &ta, NULL) < 0) error_y_exit("sigaction call error");
            //desbloqueamos y hacemos sigsuspend (ahora esperamos a q nos llegue para q se haga el tratamiento)
            sigfillset(&mask);
            sigdelset(&mask, SIGUSR1);
            sigsuspend(&mask);

            sprintf(buff, "Llista de posicions de la lletra %c: ", c);
            write(1, buff, strlen(buff));
            if(execlp("./aparicions", "./aparicions", argv[1], &c, (char*)NULL) < 0) error_y_exit("execlp call error");
        }
        else if (pids[i] < 0) error_y_exit("fork call error");
    }
    for (int i = 0; i < N; ++i) {
        alarma_recibida = 0;
        alarm(S);
        while (!alarma_recibida);
        if (kill(pids[i], SIGUSR1) < 0) error_y_exit("kill call error");
    }
    while (waitpid(-1, NULL, 0) > 0);
    exit(0);
}