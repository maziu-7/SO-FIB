#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>

void Usage() {
    char buff[256];
    sprintf(buff, "Usage: ./aparicions3 textfile1 characters_file file_out N S\n");
    write(1, buff, strlen(buff));
    exit(0);
}

void error_y_exit(char *s) {
    perror(s);
    exit(EXIT_FAILURE);
}

void func() {

}

int main(int argc, char* argv[]) {
    if (argc != 6) Usage();
    int N = atoi(argv[4]);
    int S = atoi(argv[5]);
    if (N <= 0) Usage();
    if (S <= 0) Usage();

    struct sigaction t;
    t.sa_handler = func;
    t.sa_flags = 0;
    sigemptyset(&t.sa_mask);
    if (sigaction(SIGCHLD, &t, NULL) < 0) error_y_exit("sigaction call error");

    int p[2];
    pipe(p);

    char buff[256];
    sprintf(buff, "--INICI DE LA CERCA (tarda %d) segons--\n", N*S);
    write(1, buff, strlen(buff));

    int pid = fork();

    int fd = open(argv[2], O_RDONLY);
    if (fd < 0) error_y_exit("open call error");
    char c;
    while (read(fd, &c, sizeof(char)) > 0) {
        write(p[1], &c, sizeof(char));
    }
    close (p[1]);

    if (pid == 0) {
        dup2(p[0], 0);
        int fdout = open(argv[3], O_WRONLY | O_CREAT | O_TRUNC, 0640);
        if (fdout < 0) error_y_exit("open call error");
        dup2(fdout, 1);
        close(p[0]); close(p[1]);
        close(fdout);
        execlp("./aparicions2", "./aparicions2", argv[1], argv[4], argv[5], (char*)NULL);
    }
    else if (pid < 0) error_y_exit("fork call error");

    sigset_t mask;
    sigfillset(&mask);
    sigdelset(&mask, SIGCHLD);
    sigsuspend(&mask);
    sprintf(buff, "--FINAL DE LA CERCA--\n");
    write(1, buff, strlen(buff));
}