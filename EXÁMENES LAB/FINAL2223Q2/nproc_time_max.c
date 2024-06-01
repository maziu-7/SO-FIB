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
	sprintf(buff,"Usage: ./nproc_time <PIDs>\n");
	write(1,&buff,strlen(buff));
	exit(0);
}

void error_y_exit(char *msg){
    perror(msg);
    exit(EXIT_FAILURE);
}

int main(int argc,char *argv[]){
    if (argc < 2) Usage();

    if ((mknod("MIPIPE", S_IFIFO|0666, 0) < 0) && (errno != EEXIST)){
	    error_y_exit("mknod call error");
    }
    
    char buff[256];
    int nhijos = argc-1;
    int max_time = 0;
    for (int i = 0; i < nhijos; ++i) {
        int pid = fork();
        if (pid == 0) {
            //1 -> MIPIPE escritura
            int fd = open("MIPIPE",O_WRONLY,0);
			dup2(fd,1);
			close(fd);
            if (execlp("./proc_time", "proc_time", argv[i+1], (char*)NULL) < 0) error_y_exit("execlp call error");
        }
        else if (pid < 0) error_y_exit("fork call error");
        int fdl = open("MIPIPE",O_RDONLY,0);
        int st;
        waitpid(pid, &st, 0);
        if (WIFEXITED(st)) {
            int codi_exit = WEXITSTATUS(st);
            if (codi_exit == 255) {
                sprintf(buff, "El PID %s no existe\n", argv[i+1]);
                write(1, buff, strlen(buff));
                exit(1);
            }
        }
        char num[20];
		read(fdl, &num, sizeof(num));
		int v = atoi(num);
		if(v > max_time) max_time = v;
    }
    sprintf(buff, "%d", max_time);
    write(1, buff, strlen(buff));
}