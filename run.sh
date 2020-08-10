#!/bin/bash

IMGS=data/*
LIN=linear
PRO=process
THR=threads

for img in $IMGS
do
	echo $img $i
	new=${img/data\//}
#	./$LIN $img saída/${new/.jpg/_linear.jpg} > /dev/null
#	./$THR $img saída/${new/.jpg/_thread.jpg} > /dev/null
	./$PRO $img saída/${new/.jpg/_process.jpg}> /dev/null
done
