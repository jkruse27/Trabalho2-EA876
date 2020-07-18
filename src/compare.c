#include "imageprocessing.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]){
	imagem I1 = abrir_imagem(argv[1]);
	imagem I2 = abrir_imagem(argv[2]);
	
	for(int i = 0; i < I1.width*I1.height; i++){
		if(I1.r[i] != I2.r[i]){
			printf("Canal Vermelho Diferente!\n");
			break;
		}
	}

	for(int i = 0; i < I1.width*I1.height; i++){
		if(I1.g[i] != I2.g[i]){
			printf("Canal Verde Diferente!\n");
			break;
		}
	}
	
	for(int i = 0; i < I1.width*I1.height; i++){
		if(I1.b[i] != I2.b[i]){
			printf("Canal Azul Diferente!\n");
			break;
		}
	}

	liberar_imagem(&I1);
	liberar_imagem(&I2);
	return 0;
}
