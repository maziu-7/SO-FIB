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
	if(argc < 2) Usage();
	char buff[256];
	int maximo = -1;
	for (int i = 1; i < argc; ++i){
		int *p = malloc(2*sizeof(int));
		pipe(p);
		int pid = fork();
		if (pid == 0){
			dup2(p[1],1);
			close(p[0]);
			close(p[1]);
			execlp("./proc_time","./proc_time",argv[i],NULL);
			error_y_exit("EXECLP",1);
		}
		int st;
		waitpid(pid,&st,0);
		if (WIFEXITED(st)){
			int codi = WEXITSTATUS(st);
			if (codi == 255) {
				sprintf(buff,"Error: el proceso con pid %s no existe\n",argv[i]);
				write(1,buff,strlen(buff));
				exit(1);
			}
		}
		close(p[1]);
		char num[20];
		read(p[0],&num,sizeof(num));
		close(p[0]);
		int v = atoi(num);
		if (v > maximo) maximo = v;
		free(p);
	}
	sprintf(buff,"%d\n",maximo);
	write(1,&buff,strlen(buff));
}