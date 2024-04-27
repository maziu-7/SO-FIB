#include <unistd.h>			// for getpid, write, fork, execlp
#include <stdio.h>			// for sprintf, perror
#include <stdlib.h>			// for exit
#include <string.h>			// for strlen
#include <sys/wait.h>			// for waitpid

void error_and_exit(char *msg) {
    perror(msg);
    exit(EXIT_FAILURE);
}

void usage() {
    char msg[256];

    sprintf(msg, "Usage: Ndistances n1 n2 [...]\n");
    write(2, msg, strlen(msg));
    exit(EXIT_FAILURE);
}

int main(int argc,char *argv[]) {
    int i, pid, fills;

    if (argc < 3) usage();

    fills = argc-2;

    for (i = 0; i < fills; i++) {
        pid = fork();
        switch (pid) {
            case -1: error_and_exit("fork");
            case 0: if(execlp("./distance", "distance", argv[1], argv[i+2], (char*)NULL) < 0) error_and_exit("execlp");
            default: if(waitpid(pid, NULL, 0) < 0 ) error_and_exit("waitpid");
	    }
    }
    return 0;
}