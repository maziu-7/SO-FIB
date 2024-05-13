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
    int nprocesos = atoi(buff);
    sprintf(buff2, "%.dat", argv[1]);
    int fd = open(buff2, O_WRONLY | O_CREAT | O_EXCL, 0644);
    if (fd < 0) {
        if (errno == EEXIST) {
            sprintf(buff2, "Quieres sobreescribir el archivo? (S/N)\n");
            write(1, buff2, strlen(buff2));
            char c;
            read(0, &c, sizeof(char)),
            if (c == 'S' || c == 's') {
                fd = open(buff2, O_WRONLY | O_TRUNC);
            }
            else if (c == 'N' || c == 'n') {
                lseek(fd, 0, SEEK_END);
            }
            else {
                sprintf(buff2, "Eres inútil, era una S o una N\n");
                write(1, buff2, strlen(buff2));
                exit(0);
            }
            write(fd, &nprocesos, sizeof(int));
        }
        else error_y_exit("open call error");
    } 
    write(fd, buff, strlen(buff));
    while (waitpid(-1, NULL, 0) > 0);
}