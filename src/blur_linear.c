#include <stdio.h>
#include "imageprocessing.h"
#include "blur.h"
#include <stdlib.h>

#define N 3

int main(int argc, char *argv[]) {
	
	imagem I;
	imagem i;
	
	I = abrir_imagem(argv[1]);
	
	i.width = I.width;
	i.height = I.height;
	i.r = malloc(sizeof(float)*I.width*I.height);
	i.g = malloc(sizeof(float)*I.width*I.height);
	i.b = malloc(sizeof(float)*I.width*I.height);
		
	blur(I.r, I.width, I.height, N, i.r);
	blur(I.g, I.width, I.height, N, i.g);
	blur(I.b, I.width, I.height, N, i.b);
	
	salvar_imagem(argv[2], &i);
	free(i.r);
	free(i.g);
	free(i.b);
	liberar_imagem(&I);
	
	return 0;
	
}
