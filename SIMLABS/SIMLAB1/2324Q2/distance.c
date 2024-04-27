#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <signal.h>
#include <sys/wait.h>

void Usage() {
    char buff[256];
    sprintf(buff, "Usage: distance n1 n2, 1 =< ni =< 127\n");
    write(1, buff, strlen(buff));
    exit(255);
}

int main(int argc, char* argv[]) {
    char buff[256];
    if (argc != 3) Usage();
    if (argv[1] > 127 || argv[1] < 1 || argv[2] < 1 || argv[1] > 127) Usage();
    else {
        int n1,n2;
        int d = (n1 ^ n2);
        sprintf(buff, "[%d] La distància entre %d i %d és %d\n", getpid(), n1, n2, d);
        write(1, buff, strlen(buff));
        exit(d);
    }
}