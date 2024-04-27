#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <signal.h>
#include <sys/wait.h>
#include <assert.h>
#include <errno.h>

#define pid_max 32768

void Usage() {
    char buff[256];
    sprintf(buff, "Usage: mostrarJP PID\n");
    write(1, buff, strlen(buff));
    exit(0);
}

void error_y_exit(char* s) {
    perror(s);
    exit(EXIT_FAILURE);
}

int main(int argc, char* argv[]) {
    assert(argc == 2);
    int pid = atoi(argv[1]);
    assert(pid > 0 || pid < pid_max);
    assert(kill(pid, 0) < 0 || errno != ESRCH);

    int pidh = fork();
    if (pidh == 0) {
        execlp("./pstree", "pstree", "-p", argv[1], (char*)NULL);
        error_y_exit("execlp call error");
    }
    else if (pidh < 0) error_y_exit("fork call error");
    int res = waitpid(pidh, NULL, 0);
    if (res < 0 && errno != ECHILD) error_y_exit("waitpid call error");
}