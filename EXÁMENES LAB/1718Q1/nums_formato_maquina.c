#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <signal.h>
#include <string.h>
#include <sys/wait.h>
#include <fcntl.h>

void Usage() {
	char buff[256];
	sprintf(buff,"Usage: ./nums_formato_maquina file ini fin\n");
	write(1, buff, strlen(buff));
	exit(0);
}

void error_y_exit(char *s) {
	perror(s);
	exit(EXIT_FAILURE);
}

int main(int argc, char *argv[]) {
    if (argc != 4) Usage();

    int fd = open(argv[1], O_WRONLY | O_CREAT | O_TRUNC, 0666);
    if (fd < 0) error_y_exit("open call error");
    int ini = atoi(argv[2]);
    int fin = atoi(argv[3]);
    char buff[128];

    for (int i = ini; i <= fin; ++i) {
        write(fd, &buff, sizeof(int));
    }
}