#include <stdio.h>
#include "imageprocessing.h"
#include "blur.h"
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <sys/mman.h>
#include <pthread.h>
#include "cronometro.h"

#define N 5


// Struct para os argumentos da funcao medir_main
typedef struct arg{
	imagem *I;
	float *r, *g, *b;
	int width , height;
} arg;

void *medir_main(void *args){
	// Faz cast dos argumentos para tipos originais
	imagem *I = ((arg *) args)->I;
	float *r = ((arg *) args)->r;
	float *g = ((arg *) args)->g;
	float *b = ((arg *) args)->b;

	pid_t pid[3] = {-1, -1, -1};
	
	pid[0] = fork();
	if(pid[0] != 0)
		pid[1] = fork();
	if(pid[0] != 0 && pid[1] != 0)
		pid[2] = fork();
	// Cada process fica responsavel por um canal	
	if(pid[0] == 0) {
		blur((*I).r, (*I).width, (*I).height, N, r);
	}
	if(pid[1] == 0) {
		blur((*I).g, (*I).width, (*I).height, N, g);
	}
	if(pid[2] == 0) {
		blur((*I).b, (*I).width, (*I).height, N, b);
	}
	
	if(pid[0] != 0 && pid[1] != 0 && pid[2] != 0) {
		// Espera cada processo acabar
		waitpid(pid[0], NULL, 0);
        	waitpid(pid[1], NULL, 0);
        	waitpid(pid[2], NULL, 0);

		return NULL;
	}
	
}

int main(int argc, char *argv[]){
	int protection = PROT_READ | PROT_WRITE;
        int visibility = MAP_SHARED | MAP_ANON;
	
	imagem *I;
	
	I = (imagem*) mmap(NULL, sizeof(imagem), protection, visibility, 0, 0);
	*I = abrir_imagem(argv[1]);
	
	arg arg;
	arg.I = I;

	// Alocando os canais compartilhados entre os processos
	arg.r = (float*) mmap(NULL, sizeof(float)*((*I).width*(*I).height), protection, visibility, 0, 0);
	arg.g = (float*) mmap(NULL, sizeof(float)*((*I).width*(*I).height), protection, visibility, 0, 0);
	arg.b = (float*) mmap(NULL, sizeof(float)*((*I).width*(*I).height), protection, visibility, 0, 0);
	
	medir_tempo(medir_main, &arg);
        
	I->r = arg.r;
	I->g = arg.g;
	I->b = arg.b;

	salvar_imagem(argv[2], &(*I));

	return 0;
}
