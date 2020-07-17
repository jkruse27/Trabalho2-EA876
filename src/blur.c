#include <stdlib.h>
#include "blur.h"
#include "imageprocessing.h"

void blur(float *a, int width, int height, int N, float *f) {

	int area;
	int soma;
	
	for(int i = 0; i < (width*height); i++) {
		soma = 0;
		area = N*N;
		for(int j = i-(((N-1)/2)*width); j <= i+(((N-1)/2)*width); j += width) {
			for(int k = -(N-1)/2; k < (N-1)/2; k++) {
				if((j+k < 0) || (j+k >= width*height)) {
					area--;
				}
				else {
					soma += a[j+k]; 
				}
			}
		}
		f[i] = soma/area;
	}
}

