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
    int *p = malloc(nhijos*2*sizeof(int));
    int pids[nhijos];
    for (int i = 0; i < nhijos; ++i) {
        pipe(p[i]);
        pids[i] = fork();
        if (pids[i] == 0) {
            //1 -> MIPIPE escritura
            dup2(p[i][1],1);
            close(p[i][0]); close(p[i][1]);
            if (execlp("./proc_time", "proc_time", argv[i+1], (char*)NULL) < 0) error_y_exit("execlp call error");
        }
        else if (pids[i] < 0) error_y_exit("fork call error");
    }
    int st;
    int muerto;
    while((muerto = waitpid(-1, &st, 0)) > 0) {
        if (WIFEXITED(st)) {
            int codi_exit = WEXITSTATUS(st);
            if (codi_exit == 255) {
                int i = 0;
                while (pids[i] != muerto) ++i;
                sprintf(buff, "El PID %s no existe\n", muerto);
                write(1, buff, strlen(buff));
                exit(1);
            }
            else {
                char num[20];
                int j = 0;
                close(p[1]);
                while (read(p[0], &num[i], sizeof(char)) > 0) ++i;
                int numm = atoi(num);
                if (numm > max_time) max_time = numm;
                close(p[0]);
            }
        }
    }
    sprintf(buff, "%d", max_time);
    write(1, buff, strlen(buff));
    free(p);
}