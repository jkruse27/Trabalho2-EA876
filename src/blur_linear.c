#include <stdio.h>
#include "imageprocessing.h"
#include "blur.h"

#define N 3

int main(int argc, char *argv[]) {
	
	imagem I;
	
	I = abrir_imagem(argv[1]);
		
	blur(I.r, I.width, I.height, N, I.r);
	blur(I.g, I.width, I.height, N, I.g);
	blur(I.b, I.width, I.height, N, I.b);
	
	salvar_imagem("saída/blur_linear.jpg", &I);
	liberar_imagem(&I);
	
	return 0;
	
}
