#include "imageprocessing.h"
#include "blur.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <pthread.h>
#include "cronometro.h"

#define N 15

// Struct para guardar apenas 1 cor e a largura e altura dela
typedef struct argument{
	float *color;
	void *new_color;
	int width, height;
} argument;

typedef struct arg{
	argument r, g, b;
} arg;

void *worker(void *arg){
	argument *real_arg = (argument *) arg; 								// Faz um cast para o tipo original
	blur(real_arg->color, real_arg->width, real_arg->height, N, real_arg->new_color); 		// Realiza o blur
	return (void *) real_arg->new_color; 								// Retorna o novo vetor com o blur aplicado
}


void *medir_main(void *args){
	pthread_t r, g, b;
		
	argument r_arg = ((arg *) args)->r;
	argument g_arg = ((arg *) args)->g;
	argument b_arg = ((arg *) args)->b;
	
	// Cria uma thread para tratar de cada cor independentemente
	pthread_create(&r, NULL, worker, (void *) &r_arg);
	pthread_create(&g, NULL, worker, (void *) &g_arg);
	pthread_create(&b, NULL, worker, (void *) &b_arg);

	// Salva os retornos de cada thread
	pthread_join(r, &(r_arg.new_color));
	pthread_join(g, &(g_arg.new_color));
	pthread_join(b, &(b_arg.new_color));

	return NULL;
}

int main(int argc, char *argv[]){
	
	// Abre a imagem
	imagem I = abrir_imagem(argv[1]);

	// Cria as srtucts de argumento para cada thread
	argument r_arg, g_arg, b_arg;
	
	r_arg.color = I.r;
	r_arg.width = I.width;
	r_arg.height = I.height;
	r_arg.new_color = malloc(sizeof(float)*I.width*I.height);
	
	g_arg.color = I.g;
	g_arg.width = I.width;
	g_arg.height = I.height;
	g_arg.new_color = malloc(sizeof(float)*I.width*I.height);

	b_arg.color = I.b;
	b_arg.width = I.width;
	b_arg.height = I.height;
	b_arg.new_color = malloc(sizeof(float)*I.width*I.height);

	arg args;
	args.r= r_arg;
	args.g = g_arg;
	args.b = b_arg;

	medir_tempo(medir_main, &args);
	
	liberar_imagem(&I);
	
	// Atualiza a imagem com os novos valores com blur
	I.r = (float *) r_arg.new_color;
	I.g = (float *) g_arg.new_color;
	I.b = (float *) b_arg.new_color;
	
	// Salva a imagem e libera ela
	salvar_imagem(argv[2], &I);
	
	liberar_imagem(&I);
	
	return 0;
}
