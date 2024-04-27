#include <unistd.h>			// for getpid, write, fork, execlp
#include <stdio.h>			// for sprintf, perror
#include <stdlib.h>			// for exit
#include <string.h>			// for strlen
#include <sys/wait.h>			// for waitpid

struct min_distance {
    int pid;
    int dist;
};

void error_and_exit(char *msg) {
    perror(msg);
    exit(EXIT_FAILURE);
}

void usage() {
    char msg[256];

    sprintf(msg, "Usage: Mindistance n1 n2 [...]\n");
    write(2, msg, strlen(msg));
    exit(EXIT_FAILURE);
}

int main(int argc,char *argv[]) {
    int i, pid, fills, status;
    char buff[128];
    struct min_distance mdist;

    if (argc < 3) usage();

    mdist.pid = -1;
    mdist.dist = 255;

    fills = argc-2;

    for (i = 0; i < fills; i++) {
        pid = fork();
        switch (pid) {
            case -1: error_and_exit("fork");
            case 0: if(execlp("./distance", "distance", argv[1], argv[i+2], (char*)NULL) < 0) error_and_exit("execlp");
            default:
                if(waitpid(pid, &status, 0) < 0) error_and_exit("waitpid");
	        else {
    	            if(WIFEXITED(status) && (WEXITSTATUS(status) != 255) && (WEXITSTATUS(status) < mdist.dist)) { 
	  	        mdist.pid = pid;
		        mdist.dist = WEXITSTATUS(status);
	            } 
	        }
	    }	
    }
    if (mdist.pid != -1) {
        sprintf(buff,"[%d] El procés %d ha retornat la distància mínima = %d\n", getpid(), mdist.pid, mdist.dist);
        write(1, buff, strlen(buff));
    }

    return 0;
}