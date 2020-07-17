for i in {1..100..1} 
do
	time -o main_1.txt  -a -f "%e" ./main images/cachorro.jpg
	time -o main1_1.txt -a -f "%e" ./main1 images/cachorro.jpg
	time -o main2_1.txt -a -f "%e" ./main2 images/cachorro.jpg 
	time -o main_2.txt  -a -f "%e" ./main  images/cachorro.jpg
	time -o main1_2.txt -a -f "%e" ./main1 images/cachorro.jpg
	time -o main2_2.txt -a -f "%e" ./main2 images/cachorro.jpg
	time -o main_3.txt  -a -f "%e" ./main  images/cachorro.jpg 
	time -o main1_3.txt -a -f "%e" ./main1 images/cachorro.jpg
	time -o main2_3.txt -a -f "%e" ./main2 images/cachorro.jpg
done
