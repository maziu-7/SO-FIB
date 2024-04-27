#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <signal.h>
#include <sys/wait.h>
#include <assert.h>
#include <errno.h>

void Usage() {
    char buff[256];
    sprintf(buff, "Usage: PID1 [PID2...PIDN]\n");
    write(1, buff, strlen(buff));
    exit(0);
}

void error_y_exit(char* s) {
    perror(s);
    exit(EXIT_FAILURE);
}

void trata_chld() {
    int muerto, st;
    char buff[256];
    while ((muerto = waitpid(-1, &st, WNOHANG)) > 0) {
        if (WIFEXITED(st)) {
            int code = WEXITSTATUS(st);
            sprintf(buff, "El procés %d ha acabat per exit amb codi %d\n", muerto, code);
            write(1, buff, strlen(buff));
        }
        else if (WIFSIGNALED(st)) {
            int code = WTERMSIG(st);
            sprintf(buff, "El procés %d ha acabat per signal %d\n", muerto, code);
            write(1, buff, strlen(buff));
        }
        --hmuertos;
    }
}

int main(int argc, char* argv[]) {
    assert(argc > 1 && errno != ESRCH);

    struct sigaction t;
    t.sa_handler = trata_chld;
    sigemptyset(&t.sa_mask);
    t.sa_flags = 0;
    if (sigaction(SIHCHLD, &t, NULL) < 0) error_y_exit("sigaction SIGCHLD");

    int hmuertos = argc-1;
    for (int i = 0; i < hmuertos; ++i) {
        int pidh = fork();
        if (pidh == 0) {
            if (execlp("./mostrarJP", "mostrarJP", argv[i+1], (char*)NULL) < 0) error_y_exit("execlp");
        }
        else if (pidh < 0) error_y_exit("fork");
    }
    while (hmuertos > 0);
}