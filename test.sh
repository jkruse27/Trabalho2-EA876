
for n in seq 1 100; do
	time (./main < "images/cachorro.jpg") >> main_1.txt
	time (./main1 < "images/cachorro.jpg") >> main1_1.txt
	time (./main2 < "images/cachorro.jpg") >> main2_1.txt
	time (./main < "images/cachorro.jpg") >> main_2.txt
	time (./main1 < "images/cachorro.jpg") >> main1_2.txt
	time (./main2 < "images/cachorro.jpg") >> main2_2.txt
	time (./main < "images/cachorro.jpg") >> main_3.txt
	time (./main1 < "images/cachorro.jpg") >> main1_3.txt
	time (./main2 < "images/cachorro.jpg") >> main2_3.txt
done
