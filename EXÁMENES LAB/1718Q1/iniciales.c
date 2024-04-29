#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <signal.h>
#include <string.h>
#include <sys/wait.h>
#include <fcntl.h>

void Usage() {
	char buff[256];
	sprintf(buff,"Usage: ./iniciales file\n");
	write(1, buff, strlen(buff));
	exit(0);
}

void error_y_exit(char *s) {
	perror(s);
	exit(EXIT_FAILURE);
}

int main(int argc, char *argv[]) {
    if (argc != 2) Usage();

    int fd = open(argv[1], O_RDONLY);
    if (fd < 0) error_y_exit("open call error");
    char buff[128];
    sprintf(buff, "%s.iniciales.txt", argv[1]);
    int fd2 = open(buff, O_WRONLY | O_CREAT | O_TRUNC, 0666);
    if (fd2 < 0) error_y_exit("open call error");

    int leidos;
    while ((leidos = read(fd, &buff, 128*sizeof(char))) > 0) {
        write(fd2, &buff[0], sizeof(char));
        for (int i = 1; i < leidos; ++i) {
            if (buff[i-1] == ' ') write(fd2, &buff[i], sizeof(char));
        }
    }
}