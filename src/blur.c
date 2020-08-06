#include <stdlib.h>
#include "blur.h"
#include "imageprocessing.h"
#include <stdio.h>

void blur(float *a, int width, int height, int N, float *f) {

	int area;
	float soma;
	
	for(int i = 0; i < (width*height); i++) {
		soma = 0;
		area = N*N;
		for(int j = (1-N)/2; j <= (N-1)/2; j++) {
			for(int k = (1-N)/2; k <= (N-1)/2; k++) {
				if(((int)(i/width) + j < 0) || ((int)(i/width) + j >= height) || ((int)(i%width) + k < 0) || ((int)(i%width) + k >= width)) {
					area--;
				}
				else {
					soma += a[i+(j*width)+k]; 
				}
			}
		}
		f[i] = soma/area;
	}
}

