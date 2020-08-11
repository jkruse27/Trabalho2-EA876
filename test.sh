#!/bin/bash

IMGS=data/*
LIN=linear
PRO=process
THR=threads
end=300

for img in $IMGS
do
	for (( i=0; i<=end; i++ )) do
		echo $img $i
		new=${img/data\//}
		./$LIN $img saída/${new/.jpg/_linear.jpg}  |& tee -a ${new/.jpg/_linear.txt}  > /dev/null
		./$THR $img saída/${new/.jpg/_thread.jpg}  |& tee -a ${new/.jpg/_thread.txt}  > /dev/null
		./$PRO $img saída/${new/.jpg/_process.jpg} |& tee -a ${new/.jpg/_process.txt} > /dev/null
	done
done
