#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <signal.h>
#include <string.h>
#include <sys/wait.h>

int alarma_recibida = 0;

void Usage() {
	char buff[256];
	sprintf(buff,"Usage: ./signals N\n");
	write(1,&buff,strlen(buff));
	exit(0);
}

void error_y_exit(char* s, int error) {
	perror(s);
	exit(error);
}

void trata(int s) {
    if (s == SIGALRM) alarma_recibida = 1;
}

int main(int argc, char* argv[]) {
    char buff[256];
    if (argc != 2) Usage();
    int N = atoi(argv[1]);

    sigset_t mask;
    sigemptyset(&mask);
    sigaddset(&mask, SIGUSR1);
    if (sigprocmask(SIG_BLOCK, &mask, (char*)NULL) < 0) error_y_exit("sigprocmask call error", 1);

    struct sigaction t;
    t.sa_handler = trata;
    sigemptyset(&t.sa_mask);
    t.sa_flags = 0;
    if (sigaction(SIGUSR1, &t, NULL) < 0) error_y_exit("sigaction call error", 1);
    if (sigaction(SIGALRM, &t, NULL) < 0) error_y_exit("sigaction call error", 1);

    for (int i = 0; i < N; i++) {
        int pid = fork();
        if (pid == 0) {
            sprintf(buff, "Hijo %d\n", getpid());
            write(1, buff, strlen(buff));
            alarm(1);
            while (alarma_recibida == 0);
            kill(getppid(), SIGUSR1);
            exit(0);
        }
        else if (pid < 0) error_y_exit("Fork call error", 1);

        sigset_t mask;
        sigfillset(&mask);
        sigdelset(&mask, SIGUSR1);
        sigsuspend(&mask);
    }
}

/*
0. (no tiene porque hacerse siempre, depende del ej y de lo que me pidan) bloqueo los signals que necesito (sigprocmask)
1. reprogramo mis signals (hago el sigaction)
2. desbloqueo los signals que quiero tratar (creo mask para el sigsuspend)
3. trato los signals (hago el sigsuspend pasandole la mask que acabo de crear (se va a func a hacer su tratamiento))
*/