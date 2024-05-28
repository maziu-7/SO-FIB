#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <errno.h>
#include <sys/wait.h>
#include <signal.h>

int alarma = 0;

void Usage() {
	char buff[256];
	sprintf(buff,"Usage: ./max_5sec <PIDs>\n");
	write(1,&buff,strlen(buff));
	exit(0);
}

void error_y_exit(char *msg){
    perror(msg);
    exit(EXIT_FAILURE);
}

void func(int n) {
    if (n == SIGALRM) {
        alarma = 1;
    } 
    else if (n == SIGUSR1) {
        char buff[256];
        sprintf(buff, %d, getpid());
        write(1, buff, strlen(buff));
        if (execlp("./proc_time","./proc_time", buff, (char*)NULL) < 0) error_y_exit("execlp call error");
    }
}

int main(int argc,char *argv[]) {
    if (argc < 2) Usage();
    
    sigset_t mask;
    sigemptyset(&mask);
    sigaddset(&mask, SIGALRM);
    sigaddset(&mask, SIGUSR1);

    struct sigaction t;
    t.sa_mask(&mask);
    t.sa_handler = func;
    t.sa_flags = 0;
    sigemptyset(t.sa_mask);
    if (sigaction(SIGUSR1, &t, 0) < 0) error_y_exit("sigaction call error");
    if (sigaction(SIGALRM, &t, 0) < 0) error_y_exit("sigaction call error");

    sigfillset(&mask);
    sigdelset(&mask, SIGALRM);
    sigdelset(&mask, SIGUSR1);

    while (1) {
        alarm(5);
        sigsupend(&mask);
        if (alarma) {
            int pid = fork();
			if(pid == 0) {
				argv[0] = "./nproc_time_max";
				execvp("./nproc_time_max", argv);
				error_y_exit("execvp");
			}
        }
        alarma = 0;
    }
}