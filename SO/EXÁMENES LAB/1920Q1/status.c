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

void error_y_exit(char *s, int error) {
	perror(s);
	exit(error);
}

int main(int argc, char* argv[]) {
    char buff[256];
    if (argc < 2) Usage();
    int nhijos = argc - 1;
    for (int i = 0; i < nhijos; i++) {
        int pid = fork();
        if (pid == 0) {
            sprintf(buff, "/proc/%s/status", argv[i+1]);
            execlp("grep", "grep", "State", buff, (char*)NULL);
            error_y_exit("execlp call error", 1);
        }
        else if (pid < 0) error_y_exit("fork call error", 1);
    }
}