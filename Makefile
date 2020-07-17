all:src/blur_linear.c src/blur_process.c src/blur_threads.c
	gcc -omain src/blur_linear.c src/imageprocessing.c src/blur.c -lfreeimage
	gcc -omain1 src/blur_process.c src/imageprocessing.c src/blur.c -lfreeimage -lpthread
	gcc -omain2 src/blur_threads.c src/imageprocessing.c src/blur.c -lfreeimage -lpthread	

test:all
	echo "Rodando testes..."
	chmod +x test.sh
	./test.sh	
	echo "Pronto!"
	
	python3.7 histogram.py

clean:
	rm main*
