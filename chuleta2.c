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
	sprintf(buff,"Usage: ./program nprocs nelems\n");
	write(1,&buff,strlen(buff));
	exit(0);
}

void error_y_exit(char *msg){
    perror(msg);
    exit(EXIT_FAILURE);
}

int main(int argc,char *argv[]){}

/**CONTROL D'ERRORS**/

/*
- fork
- execlp
- open
- read/write
- pipe
*/
int fd = open("file.txt",O_RDONLY);
if(fd < 0) error_y_exit("Error al abrir el fichero",2);



/**OPEN**/

//De lectura
int fent = open(argv[2],O_RDONLY);
//De escritura
int fsal = open(argv[2],O_WRONLY);
//De lectura/escritura
int f = open(argv[2],O_RDWR);

//Obre un fitxer d'escriptura, si existeix el sobreescriu i si no existeix el crea amb els permisos
int fsal = open(argv[2],O_WRONLY | O_TRUNC | O_CREAT,0640);

//EXEMPLE PERMISOS:
user	group	other
rwe		rwe 	rwe
110		000		000
6		0		0
110		100		000
6		4		0
/*****PIPES*****/

//Per crear una pipe amb nom:

if ((mknod("MIPIPE", S_IFIFO|0666, 0) < 0) && (errno != EEXIST)){
	error_y_exit("ERROR EN EL MKNOD",1);
}

int fdw = open("MIPIPE", O_WRONLY);
if (fdw < 0){
	error_y_exit("ERROR EN EL OPEN",1);
}
int fdr = open("MIPIPE", O_RDONLY);
if (fdr < 0){
	error_y_exit("ERROR EN EL OPEN",1);
}
//Per obrir un fitxer:
if ((fd = open(argv[1], O_RDONLY)) < 0){
	error_y_exit("ERROR EN EL OPEN",1);
}
//Per crear una pipe sense nom:
	int p[2];
	pipe(p);
	//des d'aquest moment p[0] és el canal de lectura de la pipe i p[1] el d'escriptura

//Per llegir caracter a caracter de la pipe p:
	char c;
	while((read(p[0],&c,sizeof(char))) > 0){
		...
	}

//Per escriure un caracter a la pipe p:
	char c = 'A';
	write(p[1],&c,sizeof(char));

//Per escriure un missatge amb variables a la terminal:
//ATENCIÓ: Per escriure un buffer feu strlen i no sizeof!
	char buff[256];
	sprintf(buff,"Hola, què tal? Sóc el procés %d",pid);
	write(1,buff,strlen(buff));

/*-------------LSEEK-------------*/
//consultar size del fitxer
int size = lseek(fd,0,SEEK_END)

//posar-lo a la posicio 3 (retorna 3)
int pos = lseek(fd,3,SEEK_SET)

//posar-lo a la penúltima posicio
int pos = lseek(fd,-1,SEEK_END)

//posar-lo 2 posicions endavant de on esta actualment el punter
int pos = lseek(fd,2,SEEK_CUR)

//posar-lo 2 posicions enrere de on esta actualment el punter
int pos = lseek(fd,-2,SEEK_CUR)