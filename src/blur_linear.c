#include <stdio.h>
#include "imageprocessing.h"
#include "blur.h"
#include <stdlib.h>

#define N 7

int main(int argc, char *argv[]) {
	
	imagem I;
	
	I = abrir_imagem(argv[1]);

	float *r, *g, *b;
	r = malloc(I.width*I.height*(sizeof(float)));
	g = malloc(I.width*I.height*(sizeof(float)));
	b = malloc(I.width*I.height*(sizeof(float)));
		
	blur(I.r, I.width, I.height, N, r);
	blur(I.g, I.width, I.height, N, g);
	blur(I.b, I.width, I.height, N, b);
	
	liberar_imagem(&I);
	
	I.r = r;
	I.g = g;
	I.b = b;

	salvar_imagem(argv[2], &I);
	liberar_imagem(&I);
	
	return 0;
	
}
