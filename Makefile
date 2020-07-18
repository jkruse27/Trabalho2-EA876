CC = gcc
CFLAGS = -lfreeimage
EFLAGS = -pthread
LFILE = $(DIR)/blur_linear.c
TFILE = $(DIR)/blur_threads.c
PFILE = $(DIR)/blur_process.c
DEP = $(DIR)/imageprocessing.c $(DIR)/blur.c
LTARGET = linear
TTARGET = threads
PTARGET = process
DIR = src

TEST = test.sh
HIST = histogram.py
PY = python3.7

all:src/blur_linear.c src/blur_process.c src/blur_threads.c
	$(CC) -o$(LTARGET) $(LFILE) $(DEP) $(CFLAGS)
	$(CC) -o$(TTARGET) $(TFILE) $(DEP) $(CFLAGS) $(EFLAGS)
	$(CC) -o$(PTARGET) $(PFILE) $(DEP) $(CFLAGS) $(EFLAGS)

test:all
	echo "Rodando testes..."
	./$(TEST)	
	echo "Pronto!"
	
	$(PY) $(HIST)

clean:
	rm -f $(LTARGET)
	rm -f $(PTARGET)
	rm -f $(TTARGET)
	rm -f *.txt
