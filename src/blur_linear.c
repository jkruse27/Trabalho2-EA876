#include <stdio.h>
#include "imageprocessing.h"
#include "blur.h"
#include <stdlib.h>
#include "cronometro.h"

#define N 15

// Struct
typedef struct arg{
	imagem I;
	float *r, *g, *b;
}arg;

// Funcao que implementa blur
void *medir_main(void *args){
	imagem I = ((arg *) args)->I;
	float *r = ((arg *) args)->r;
	float *g = ((arg *) args)->g;
	float *b = ((arg *) args)->b;
	
	// Aplica o blur salvando nos canais alocados acima
	blur(I.r, I.width, I.height, N, r);
	blur(I.g, I.width, I.height, N, g);
	blur(I.b, I.width, I.height, N, b);
	
	return NULL;
}

int main(int argc, char *argv[]){
	arg arg;
	
	arg.I = abrir_imagem(argv[1]); // Abre imagem

	arg.r = malloc((arg.I).width*(arg.I).height*(sizeof(float)));
	arg.g = malloc((arg.I).width*(arg.I).height*(sizeof(float)));
	arg.b = malloc((arg.I).width*(arg.I).height*(sizeof(float)));
		

	medir_tempo(medir_main, &arg);
	
	liberar_imagem(&(arg.I));
	
	(arg.I).r = arg.r;
	(arg.I).g = arg.g;
	(arg.I).b = arg.b;
	
	// Salva imagem com blur
	salvar_imagem(argv[2], &(arg.I));
	liberar_imagem(&(arg.I));
	return 0;
}
