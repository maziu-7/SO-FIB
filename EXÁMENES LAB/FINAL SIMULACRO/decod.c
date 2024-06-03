#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <signal.h>
#include <errno.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>

void Usage() {
    char buff[256];
    sprintf(buff, "Usage: ./decod coded_file ntextos i\n");
    write(1, buff, strlen(buff));
}

void error_y_exit(char *msg) {
    perror(msg);
    exit(EXIT_FAILURE);
}

int main(int argc, char* argv[]) {

}