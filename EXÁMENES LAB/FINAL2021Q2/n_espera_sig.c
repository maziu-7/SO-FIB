#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <signal.h>
#include <errno.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>

void Usage() {
    char buff[256];
    sprintf(buff, "./n_espera_sig N\n");
    write(1, buff, strlen(buff));
    exit(0);
}

void error_y_exit(char *msg) {
    perror(msg);
    exit(EXIT_FAILURE);
}

int main(int argc, char* argv[]) {
    char buff[256];
    if (argc != 2) Usage();
    int N = atoi(argv[1]);
    int *pids = sbrk(sizeof(int)*N);

    for (int i = 0; i < N; ++i) {
        pids[i] = fork();
        if (pids[i] == 0) {
            sprintf(buff, "HIJO %d, PID %d\n", i, getpid());
            write(1, buff, strlen(buff));
            if (execlp("./espera_sig", "espera_sig", (char*)NULL) < 0) error_y_exit("execlp call error");
        }
        else if (pids[i] < 0) error_y_exit("fork call error");
    }
    //hacemos el fichero que nos pide con sus respectivos flags y permisos
    int fd = open("exit_status.int", O_WRONLY | O_CREAT | O_TRUNC, 0640);
    if (fd < 0) error_y_exit("open call error");
    
    int st,pid;

    //mientras se vayan muriendo hijos, recogemos sus pids
    while((pid = waitpid(-1, &st, 0)) > 0) {
        //si ha hecho exit
        if (WIFEXITED(st)) {
            int code_exit = WEXITSTATUS(st);
            int i = 0;
            //recorremos todos los pids para buscar el de la posición i
            //asi los sacamos en orden
            while (pids[i] != pid) ++i;

            //tenemos q poner dos ints en la posición i: PID y EXIT
            lseek(fd, 2*i*sizeof(int), SEEK_SET);
            //escribimos primero PID y luego EXIT
			write(fd, &pid, sizeof(int));
			write(fd, &code_exit, sizeof(int));

            sprintf(buff, "HIJO %d HA HECHO EXIT %d\n", pids[i], code_exit);
            write(1, buff, strlen(buff));
        }
    }
    //cerramos el fichero pq ya hemos acabado de escribir
    close(fd);

    //liberamos la memoria ocupada al principio
    sbrk(-(sizeof(int)*N));

    //escribimos todos los ints del fichero para comprobar su contenido
    fd = open("exit_status.int", O_RDONLY);
	int x,y;
	while(read(fd, &x, sizeof(int)) > 0){
		read(fd, &y,sizeof(int));
		sprintf(buff, "FICHERO .INT: PID %d CON EXIT %d\n", x, y);
		write(1, &buff, strlen(buff));
	}
}