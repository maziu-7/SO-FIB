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
	sprintf(buff,"Usage: ./proc_time PID\n");
	write(1,&buff,strlen(buff));
	exit(0);
}

void error_y_exit(char *msg){
    perror(msg);
    exit(EXIT_FAILURE);
}

int main(int argc,char *argv[]){
    if (argc != 2) Usage();
    char buff[256];
    sprintf(buff, "/proc/%s/stat", argv[1]);
    int fd = open(buff, O_RDONLY);
    if (fd < 0) exit(255);

    char c;
    for (int i = 0; i < 13; ++i) {
        while (read(fd, &c, sizeof(char)) > 0 && c != ' ');
    }
    char utime[20];
    int i = 0;
    while (read(fd, &utime[i], sizeof(char)) > 0 && utime[i] != ' ') ++i;

    char stime[20];
    i = 0;
    while (read(fd, &stime[i], sizeof(char)) > 0 && stime[i] != ' ') ++i;
    int valor14 = atoi(utime);
    int valor15 = atoi(stime);
    int suma = valor14 + valor15;

    sprintf(buff, "%d", suma);
    write(1, buff, strlen(buff));
}