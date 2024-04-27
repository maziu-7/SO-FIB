/*PROGRAMA BASE PER COPIAR I ENGANXAR*/
/*------------------------------------*/
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <signal.h>
#include <string.h>
#include <sys/wait.h>

void Usage() {
	char buff[256];
	sprintf(buff,"Usage: ./program nprocs nelems\n");
	write(1, buff, strlen(buff));
	exit(0);
}

void error_y_exit(char *s) {
	perror(s);
	exit(EXIT_FAILURE);
}

int main(int argc, char *argv[])
{}

/*INCLUDES*/
/*------------------------------------*/
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <signal.h>
#include <string.h>
#include <sys/wait.h>


/*USAGE*/
/*------------------------------------*/
void Usage() {
	char buff[256];
	sprintf(buff, "Usage: ./program nprocs nelems\n");
	write(1, buff, strlen(buff));
	exit(0);
}
/*ERROR Y EXIT*/
/*------------------------------------*/
//1. imprime por el canal estandar de entrada el string s
//2. sale con el codigo error
void error_y_exit(char *s) {
	perror(s);
	exit(EXIT_FAILURE);
}

//Ejemplo de uso de error_y_exit:
error_y_exit("execlp call error\n", 1);

/*PROGRAMA PRINCIPAL*/

int main(int argc, char* argv[])
{}

/*ESCRIURE A LA TERMINAL*/

/*Per escriure amb variables: sprintf*/
/*
%d -> int
%c -> char
%s -> string
%f -> float
*/
char buff[256];
sprintf(buff,"Hola, soc la millor i el pid es: %d\n",pid);
write(1, buff, strlen(buff));
	
/*PASSAR DE STRING (char*) A INT*/
int x = atoi(argv[1]);

/*PASSAR DE INT A STRING*/
char buff[256];
sprintf(buff, "%d",x);


/*SIGNALS*/

/*Per enviar un signal a un proces: kill*/
int x = kill(pid, SIGALRM);
/* 	x == 0 -> tot ok
	x == -1 -> error (segurament pq no existeix el pid)
*/

/*Modificar mascara del procés*/
/*------------------------------------*/
//Bloqueja el SIGCHLD i el SIGALRM
sigset_t mask;
sigemptyset(&mask);
sigaddset(&mask, SIGCHLD);
sigaddset(&mask, SIGALRM);
sigprocmask(SIG_BLOCK, &mask, NULL);

/*Reprogramar signal*/
/*------------------------------------*/
//Si queremos bloquear todas las signals mientras tratamos SIGALRM
struct sigaction trat;
trat.sa_handler = func;
trat.sa_flags = 0;
sigfillset(&trat.sa_mask); 
sigaction(SIGALRM, &trat, NULL);
// si no queremos bloquear ninguna signal extra mientras tratamos SIGALRM
struct sigaction trat;
trat.sa_handler = func;
trat.sa_flags = 0;
sigemptyset(&trat.sa_mask); 
sigaction(SIGALRM, &trat, NULL);

/*Obtenció del codi de exit d'un fill*/
/*------------------------------------*/
void finalitzacio_fill(int pid) {
	//Esperem a que es mori el fill per saber com ha acabat
	int status;
	waitpid(pid,&status,0); //o el 0 podria ser WNOHANG
	//Si ha acabat amb un exit
	if (WIFEXITED(status))
    {
        int exitcode = WEXITSTATUS(status);
        printf("El proceso %d termina con exit code %d\n", pid, exitcode);
    }
    else {
        // Ha terminado por un signal
        int signalcode = WTERMSIG(status);
        printf("El proceso %d termina con signal code %d\n", pid,  signalcode);
    }
}

/*SIGSUSPEND*/
/*------------------------------------*/
//Espera a que arribi un SIGUSR1
sigset_t mask;
sigfillset(&mask);
sigdelset(&mask, SIGUSR1);
sigsuspend(&mask);

/*-------------WAITPID-------------*/
//Bloqueante (1 hijo)
int pid_liberado = waitpid(-1,NULL,0);

int pid_liberado = waitpid(pid,NULL,0);

int status;
int pid_liberado = waitpid(-1,&status,0);

//Bloqueante (todos los hijos)
while(waitpid(-1,NULL,0) > 0);

//No bloqueante
int status;
int pid_liberado = waitpid(-1,&status,WNOHANG);

/*-------------EXECLP-------------*/
//MIGRACIÓ A UN EXECUTABLE QUE ESTÀ A LA MATEIXA CARPETA!!!!
//Migrar sense params
execlp("./program.exe","./program.exe",NULL);

//Migrar amb un param que es un int
int x = 4;
char buff[256];
sprintf(buff,"%d",x);
execlp("./program.exe","./program.exe",buff,NULL);

//Migrar amb un param que es un char* (p.ex argv[2])
execlp("./program.exe","./program.exe",argv[2],NULL);

//MIGRACIÓ A UN PROGRAMA DE LINUX
execlp("ls","ls",NULL);

execlp("grep","grep","paraula","fitxer",NULL);

/*-------------MEMORIA-------------*/

//crida a sistema
int *pids = sbrk(nprocs*sizeof(int));
//Funcions de C 
int *pids = malloc(nprocs*sizeof(int));
free(pids);

/*-------------OTROS-------------*/
//Mirar si hi ha un proces executant-se:
ps -aux | grep nom_programa
