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
	sprintf(buff,"Usage: ./userprocs\n");
	write(1, buff, strlen(buff));
	exit(0);
}

void error_y_exit(char *msg){
    perror(msg);
    exit(EXIT_FAILURE);
}

int main(int argc,char *argv[]) {
    char buff[256];
    if (argc != 1) Usage();
    int h1 = fork();
    if (execlp("ps", "ps", "-eaf", (char*)NULL) < 0) error_y_exit("execlp call error");

    int p1[2];
    pipe(p1);

    int h2 = fork();
    if (execlp("grep", "grep", "maziu7", (char*)NULL) < 0) error_y_exit("execlp call error");

    int p2[2];
    pipe(p2);
    
    int h3 = fork();
    execlp("wc", "wc", "-l", (char*)NULL);
}