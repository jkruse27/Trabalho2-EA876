
FIG1 = cachorro.jpg
FIG2 = 
FIG3 = 


compile: main.c main1.c main2.c
	gcc -omain main.c imageprocessing.c blur.c -lfreeimage
	gcc -omain1 main1.c imageprocessing.c blur.c -lfreeimage -lpthread
	gcc -omain2 main2.c imageprocessing.c blur.c -lfreeimage -lpthread	

test:
	number=1 ;
	echo "Rodando testes..."
	while [[ $$number -le 100 ]] ; do \
		time (./main  < $(FIG1)) >> main_1.txt;
		time (./main1 < $(FIG1)) >> main1_1.txt;
		time (./main2 < $(FIG1)) >> main2_1.txt;
		time (./main  < $(FIG2)) >> main_2.txt;
		time (./main1 < $(FIG2)) >> main1_2.txt;
		time (./main2 < $(FIG2)) >> main2_2.txt;
		time (./main < $(FIG3)) >> main_3.txt;
		time (./main1 < $(FIG3)) >> main1_3.txt;
		time (./main2 < $(FIG3)) >> main2_3.txt;
        	((number = number + 1))	 ; 
	done
	echo "Pronto!"
	
	python3 histogram.py
