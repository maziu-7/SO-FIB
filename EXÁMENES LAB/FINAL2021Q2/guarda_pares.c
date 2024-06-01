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
	sprintf(buff,"Usage: ./guarda_pares pid signal\n");
	write(1,&buff,strlen(buff));
	exit(0);
}

void error_y_exit(char *s, int error) {
	perror(s);
	exit(error);
}

int main(int argc,char *argv[]){
	if(argc != 3) Usage();
	int fd = open("datos.int",O_WRONLY | O_CREAT | O_TRUNC,0666);
	int pid = atoi(argv[1]);
	int signal = atoi(argv[2]);
	write(fd,&pid,sizeof(int));
	write(fd,&signal,sizeof(int));
}