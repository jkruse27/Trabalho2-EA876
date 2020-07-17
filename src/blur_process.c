#include <stdio.h>
#include "imageprocessing.h"
#include "blur.h"
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <sys/mman.h>
#include <pthread.h>

#define N 3

int main(int argc, char *argv[]) {
	
	int protection = PROT_READ | PROT_WRITE;
        int visibility = MAP_SHARED | MAP_ANON;
	imagem *I;
	imagem i;
	
	I = (imagem*) mmap(NULL, sizeof(imagem), protection, visibility, 0, 0);
	*I = abrir_imagem(argv[1]);
	
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
		blur((*I).r, (*I).width, (*I).height, N, i.r);
	}
	if(pid[1] == 0) {
		blur((*I).g, (*I).width, (*I).height, N, i.g);
	}
	if(pid[2] == 0) {
		blur((*I).b, (*I).width, (*I).height, N, i.b);
	}
	
	if(pid[0] != 0 && pid[1] != 0 && pid[2] != 0) {
		waitpid(pid[0], NULL, 0);
        	waitpid(pid[1], NULL, 0);
        	waitpid(pid[2], NULL, 0);
        	i.width = (*I).width;
        	i.height = (*I).height;
        	liberar_imagem(&I[0]);
		salvar_imagem("saída/blur_process.jpg", &i);

		return 0;
	}
	
}
