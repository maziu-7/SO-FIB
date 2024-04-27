#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <signal.h>
#include <string.h>
#include <sys/wait.h>

void Usage() {
	char buff[256];
	sprintf(buff, "Usage: ./multi_mkdir dir1 [dir2...]\n");
	write(1, buff, strlen(buff));
	exit(0);
}

void error_y_exit(char *s, int error) {
	perror(s);
	exit(error);
}

int main(int argc, char* argv[]) {
    char buff[256];
    int i;
    int pids[argc-1];
    int p;
    if (argc < 2) Usage();
    for(i = 1; i < argc; ++i) {
        p = fork();
        if (p == -1) error_y_exit("Fork call error", 1);
        if (p == 0) {
            sprintf(buff, "Soy el hijo con PID %d, mi directorio es %s\n", getpid(), argv[i]);
            write(1, buff, strlen(buff));
            execlp("mkdir", "mkdir", argv[i], NULL);
            error_y_exit("execlp call error", 1);
        }
        waitpid(p, NULL, 0);
        pids[i-1] = p;
    }
    for (i = 1; i < argc; ++i) {
        sprintf(buff, "El hijo con PID %d ha muerto. Ha creado el directorio %s\n", pids[i-1], argv[i]);
        write(1, buff, strlen(buff));
    }
}