#!/bin/bash

IMGS=images/*
LIN=linear
PRO=process
THR=threads
end=3

for img in $IMGS
do
	for (( i=0; i<=end; i++ )) do
		echo $img $i
		new=${img/images\//}
		TIMEFORMAT='%3R'; (time ./$LIN $img saída/${new/.jpg/_linear.jpg}  > /dev/null)  |& tee -a ${new/.jpg/_linear.txt}  > /dev/null
		TIMEFORMAT='%3R'; (time ./$THR $img saída/${new/.jpg/_thread.jpg}  > /dev/null)  |& tee -a ${new/.jpg/_thread.txt}  > /dev/null
		TIMEFORMAT='%3R'; (time ./$PRO $img saída/${new/.jpg/_process.jpg} > /dev/null)  |& tee -a ${new/.jpg/_process.txt} > /dev/null
	done
done
