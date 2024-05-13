#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <errno.h>
#include <sys/wait.h>

void Usage() {
	char buff[256];
	sprintf(buff,"Usage: ./userprocs username\n");
	write(1, buff, strlen(buff));
	exit(0);
}

void error_y_exit(char *msg){
    perror(msg);
    exit(EXIT_FAILURE);
}

int main(int argc,char *argv[]) {
    if (argc != 2) Usage();

    int p1[2];
    pipe(p1);

    int h1 = fork();
    if (h1 == 0) {
        dup2(p1[1], 1);
        close(p1[0]); close(p1[1]);
        if (execlp("ps", "ps", "-eaf", (char*)NULL) < 0) error_y_exit("execlp call error");
    }

    int p2[2];
    pipe(p2);

    int h2 = fork();
    if (h2 == 0) {
        dup2(p1[0], 0);
        close(p1[0]); close(p1[1]);
        dup2(p2[1], 1);
        close(p2[0]); close(p2[1]);
        if (execlp("grep", "grep", argv[1], (char*)NULL) < 0) error_y_exit("execlp call error");
    }
    close(p1[0]); close(p1[1]);

    int p3[2];
    pipe(p3);

    int h3 = fork();
    if (h3 == 0) {
        dup2(p2[0], 0);
        close(p1[0]); close(p1[1]);
        close(p2[0]); close(p2[1]);
        dup2(p3[1], 1);
        close(p3[0]); close(p3[1]);
        if (execlp("wc", "wc", "-l", (char*)NULL) < 0) error_y_exit("execlp call error");
    }
    close(p2[0]); close(p2[1]);
    close(p3[1]);
    char buff[256];
    char buff2[256];
    int leidos = read(p3[0], buff, 256*sizeof(char));
    buff[leidos-1] = '\0';
    sprintf(buff2, "El usuario %s está ejecutando %s procesos.\n", argv[1], buff);
    write(1, buff2, strlen(buff2));

    while (waitpid(-1, NULL, 0) > 0);
}