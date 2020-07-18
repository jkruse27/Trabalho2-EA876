#include "imageprocessing.h"
#include "blur.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <pthread.h>

#define N 3

// Struct para guardar apenas 1 cor e a largura e altura dela
typedef struct argument{
	float *color;
	int width, height;
} argument;

void *worker(void *arg){
	argument *real_arg = (argument *) arg; 						// Faz um cast para o tipo original
	blur(real_arg->color, real_arg->width, real_arg->height, N, real_arg->color); 	// Realiza o blur
	
	return (void *) real_arg->color; 				// Retorna o novo vetor com o blur aplicado
}


int main(int argc, char *argv[]){
	pthread_t r, g, b;
	void *new_r, *new_g, *new_b;
	
	// Abre a imagem
	imagem I = abrir_imagem(argv[1]);

	// Cria as srtucts de argumento para cada thread
	argument r_arg, g_arg, b_arg;
	
	r_arg.color = I.r;
	r_arg.width = I.width;
	r_arg.height = I.height;
	
	g_arg.color = I.g;
	g_arg.width = I.width;
	g_arg.height = I.height;

	b_arg.color = I.b;
	b_arg.width = I.width;
	b_arg.height = I.height;
	
	// Cria uma thread para tratar de cada cor independentemente
	pthread_create(&r, NULL, worker, (void *) &r_arg);
	pthread_create(&g, NULL, worker, (void *) &g_arg);
	pthread_create(&b, NULL, worker, (void *) &b_arg);

	// Salva os retornos de cada thread
	pthread_join(r, &new_r);
	pthread_join(g, &new_g);
	pthread_join(b, &new_b);

	// Atualiza a imagem com os novos valores com blur
	I.r = (float *) new_r;
	I.g = (float *) new_g;
	I.b = (float *) new_b;
	
	// Salva a imagem e libera ela
	salvar_imagem(argv[2], &I);
	liberar_imagem(&I);
	
	return 0;
}
