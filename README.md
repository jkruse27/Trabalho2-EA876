# Projeto 2 de EA876
Por Augusto Amstalden e João Gabriel Kruse

## Objetivo

Verificar a diferença em tempo de execução de um filtro blur implementado em um programa linear, com threads e com processos.

## Requisitos

Os códigos em c são compilados utilizando gcc e precisam da biblioteca freeimage. Além disso, para o plot dos gráficos é necessário ter python3 instalado com a biblioteca matplotlib.
## Uso

*make test* rodará cada programa 100x para cada imagem em *data* medindo o tempo de execução usando a função do programa cronometro.c. Os resultados são mostrados na pasta *doc* na forma de um histograma e as imagens com blur resultantes aparecem na pasta *Saida*. As imagens precisam ser .jpg.
*make run* executará cada programa uma única vez para cada imagem da pasta *data*, salvando seu resultado na pasta *Saida*
