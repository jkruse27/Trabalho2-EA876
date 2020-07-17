#include <stdio.h>
#include "imageprocessing.h"
#include "blur.h"
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <sys/mman.h>
#include <pthread.h>


int main() {
	
	int protection = PROT_READ | PROT_WRITE;
        int visibility = MAP_SHARED | MAP_ANON;
	imagem *I;
	imagem i;
	char str[40];
	
	scanf("%s", str);
	
	I = (imagem*) mmap(NULL, sizeof(imagem), protection, visibility, 0, 0);
	*I = abrir_imagem(str);
	
	i.r = (float*) mmap(NULL, sizeof(float)*((*I).width*(*I).height), protection, visibility, 0, 0);
	i.g = (float*) mmap(NULL, sizeof(float)*((*I).width*(*I).height), protection, visibility, 0, 0);
	i.b = (float*) mmap(NULL, sizeof(float)*((*I).width*(*I).height), protection, visibility, 0, 0);
	
	pid_t pid[3] = {-1, -1, -1};
	
	pid[0] = fork();
	if(pid[0] != 0)
		pid[1] = fork();
	if(pid[0] != 0 && pid[1] != 0)
		pid[2] = fork();
	
	if(pid[0] == 0) {
		blur((*I).r, (*I).width, (*I).height, 17, i.r);
	}
	if(pid[1] == 0) {
		blur((*I).g, (*I).width, (*I).height, 17, i.g);
	}
	if(pid[2] == 0) {
		blur((*I).b, (*I).width, (*I).height, 17, i.b);
	}
	
	if(pid[0] != 0 && pid[1] != 0 && pid[2] != 0) {
		waitpid(pid[0], NULL, 0);
        	waitpid(pid[1], NULL, 0);
        	waitpid(pid[2], NULL, 0);
        	i.width = (*I).width;
        	i.height = (*I).height;
        	liberar_imagem(&I[0]);
		salvar_imagem("../saìda/blur_linear.jpg", &i);

		return 0;
	}
	
}
