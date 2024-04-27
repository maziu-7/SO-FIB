#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <signal.h>
#include <sys/wait.h>
#include <assert.h>
#include <errno.h>

int recibido;

void Usage() {
    char buff[256];
    sprintf(buff, "Usage: crearJP <NFILLS1> <NFILLS2>, 1 <= NFILLS1 <= 10, 1 <= NFILLS2 <= 5\n");
    write(1, buff, strlen(buff));
    exit(0);
}

void error_y_exit(char* s) {
    perror(s);
    exit(EXIT_FAILURE);
}

void trata_alarma() {}

void trata_sigusr(int s) {
    recibido = s;
}

int main(int argc, char* argv[]) {
    if (argc != 3) Usage();
    int nhijos1 = atoi(argv[1]);
    int nhijos2 = atoi(argv[2]);
    if (nhijos1 < 1 || nhijos1 > 10) Usage();
    if (nhijos2 < 1 || nhijos2 > 5) Usage();

    sigset_t mask;
    sigemptyset(&mask);
    sigaddset(&mask, SIGALRM);
    sigaddset(&mask, SIGUSR1);
    sigaddset(&mask, SIGUSR2);
    if (sigprocmask(SIG_BLOCK, &mask, NULL) < 0) error_y_exit("sigprocmask");

    struct sigaction t;
    t.sa_handler = trata_alarma;
    sigemptyset(&t.sa_mask);
    t.sa_flags = 0;
    if (sigaction(SIGALRM, &t, NULL) < 0) error_y_exit("sigaction SIGALRM");
    t.sa_handler = trata_sigusr;
    t.sa_flags = SA_RESETHAND;
    if (sigaction(SIGUSR1, &t, NULL) < 0) error_y_exit("sigaction SIGUSR1");
    if (sigaction(SIGUSR2, &t, NULL) < 0) error_y_exit("sigaction SIGUSR2");

    char buff[256];
    sprintf(buff, "Soy el proceso %d: raíz de la jerarquía\n", getpid());
    write(1, buff, strlen(buff));

    sigfillset(&mask);
    sigdelset(&mask, SIGUSR1);
    sigdelset(&mask, SIGUSR2);

    int pids1[nhijos1];
    int pids2[nhijos2];
    for (int i = 0; i < nhijos1; ++i) {
        pids1[i] = fork();
        if (pids1[i] == 0) {
            for (int j = 0; j < nhijos2; ++j) {
                pids2[j] = fork();
                if (pids2[j] == 0) {
                    sigsuspend(&mask);
                    sprintf(buff, "Soy el proceso %d (hijo del proceso %d): Recibido signal %s\n", getpid(), getppid(), strsignal(recibido));
                    write(1, buff, strlen(buff));
                    for (int k = 0; k < j; ++k) {
                        if (kill(pids2[k], recibido) < 0) error_y_exit("kill nietos");
                    }
                    exit(0);
                }
                else if (pids2[j] < 0) error_y_exit("fork2");
            }
            sigsuspend(&mask);
            sprintf(buff, "Soy el proceso %d (hijo del proceso %d): Recibido signal %s\n", getpid(), getppid(), strsignal(recibido));
            write(1, buff, strlen(buff));
            int r = waitpid(-1, NULL, WNOHANG);
            if (r == -1) { //no quedan hijos vivos, envio a mis hermanos mayores
                for (int k = 0; k < i; ++k) {
                    if (kill(pids1[k], recibido) < 0) error_y_exit("kill hijos (hermanos mayores)");
                }
            }
            else { //si que tengo hijos, les envio el signal
                for (int k = 0; k < nhijos2; ++k) {
                    if (kill(pids2[k], recibido) < 0) error_y_exit("kill hijos (a los nietos)");
                }
            }
            while (waitpid(-1, NULL, 0) > 0);
            exit(0);
        }
        else if (pids1[i] < 0) error_y_exit("fork1");
    }
    sigfillset(&mask);
    sigdelset(&mask, SIGALRM);

    alarm(60);
    sigsuspend(&mask);
    for (int i = 0; i < nhijos1; ++i) {
        if (kill(pids1[i], SIGUSR1) < 0) error_y_exit("kill");
    }
}