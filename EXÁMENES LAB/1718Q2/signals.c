#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <errno.h>
#include <signal.h>
#include <sys/wait.h>

int n = 0;

void Usage() {
	char buff[256];
	sprintf(buff,"Usage: ./signals N\n");
	write(1,&buff,strlen(buff));
	exit(0);
}

void error_y_exit(char *msg) {
    perror(msg);
    exit(EXIT_FAILURE);
}

void trat_alarma() {

}

void trat_sigusr1() {
    ++n;
    if (n == 3) {
        char buff[256];
        sprintf(buff, "3 SIGUSR1 recibidos. Acabando programa.\n");
        write(1, buff, strlen(buff));
        exit(0);
    }
}

int main(int argc,char *argv[]) {
    if (argc != 2) Usage();

    int n = atoi(argv[1]);

    sigset_t mask;
    sigfillset(&mask);
    sigdelset(&mask, SIGUSR1);
    sigdelset(&mask, SIGUSR2);
    sigdelset(&mask, SIGALRM);
    
    struct sigaction t;
    t.sa_handler = trat_alarma;
    sigfillset(&t.sa_mask);
    t.sa_flags = 0;
    if (sigaction(SIGALRM, &t, NULL) < 0) error_y_exit("sigaction call error");
    t.sa_handler = trat_sigusr1;
    if (sigaction(SIGUSR1, &t, NULL) < 0) error_y_exit("sigaction call error");

    char buff[256];
    for (int i = 1; i <= n; ++i) {
        alarm(1);
        sigsuspend(&mask);
        sprintf(buff, "Alarma: %d segundos\n", i);
        write(1, buff, strlen(buff));
    }
}