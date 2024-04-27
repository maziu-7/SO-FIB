#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <signal.h>
#include <string.h>
#include <sys/wait.h>

void Usage() {
	char buff[256];
	sprintf(buff,"Usage: ./status [PID]\n");
	write(1,&buff,strlen(buff));
	exit(0);
}

void error_y_exit(char* s , int error) {
	perror(s);
	exit(error);
}

int main(int argc, char* argv[]) {
    char buff[256];
    if (argc < 2 || argc > 11) Usage();
    int nhijos = argc - 1;
    int pids[nhijos];

    for (int i = 0; i < nhijos; i++) {
        pids[i] = fork();
        if (pids[i] == 0) {
            sprintf(buff, "/proc/%s/status", argv[i+1]);
            execlp("grep", "grep", "State", buff, (char*)NULL);
            error_y_exit("execlp call error", 1);
        }
        else if (pids[i] < 0) error_y_exit("fork call error", 1);
    }
    int st, muerto;
    while ((muerto = waitpid(-1, &st, 0)) > 0) {
        if (WIFEXITED(st)) {
            int codi_exit = WEXITSTATUS(st);
            if (codi_exit != 0) {
                int i = 0;
                while (muerto != pids[i]) ++i;
                sprintf(buff, "Proceso %s no existe\n", argv[i+1]);
                write(1, buff, strlen(buff));
                exit(1);
            }
        }
    }
}