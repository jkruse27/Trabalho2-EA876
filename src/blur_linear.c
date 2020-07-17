#include <stdio.h>
#include "imageprocessing.h"
#include "blur.h"

int main() {
	
	char str[40];
	imagem I;
	
	scanf("%s", str);
	I = abrir_imagem(str);
	printf("%s", str);
	
	blur(I.r, I.width, I.height, 5, I.r);
	blur(I.g, I.width, I.height, 5, I.g);
	blur(I.b, I.width, I.height, 5, I.b);
	
	salvar_imagem("../saìda/blur_linear.jpg", &I);
	liberar_imagem(&I);
	
	return 0;
	
}
