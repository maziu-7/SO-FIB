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
	sprintf(buff,"Usage: ./exam1 originFile destinyFile\n");
	write(1,&buff,strlen(buff));
	exit(0);
}

void error_y_exit(char *msg){
    perror(msg);
    exit(EXIT_FAILURE);
}

int main(int argc,char *argv[]){
    if (argc != 3) Usage();

    int pid = fork();
    int fd1 = open(argv[1], O_RDONLY);
    if (fd1 < 0) error_y_exit("open call error");
    int fd2 = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, 0640);
    if (fd2 < 0) error_y_exit("open call error");
    if (pid == 0) {
        dup2(fd1, 0);
        dup2(fd2, 1);
        if (execlp("./desc_ok", "desc_ok", (char*)NULL) < 0) error_y_exit("execlp call error");
        //close(fd1); close(fd2);
    }
    else if (pid < 0) error_y_exit("fork call error");
    waitpid(pid, NULL, 0);
    int orig = lseek(fd1, 0, SEEK_END);
    int comp = lseek(fd2, 0, SEEK_END);

    float r = comp/(float)orig;
    char buff[256];
    sprintf(buff, "Original: %d, Comprimido: %d, Relación: %f\n", orig, comp, r);
    write(2, &buff, strlen(buff));
}