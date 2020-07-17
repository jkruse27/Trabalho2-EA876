import matplotlib.pyplot as plt
import numpy as np

m1, m2, m3, m12, m22, m32, m13, m23, m33 = [], [], [], [], [], [], [], [], []

with open("main_1.txt", "r") as f:
	for i in f:
		m1.append(float(i))
with open("main_2.txt", "r") as f:
	for i in f:
		m12.append(float(i))
with open("main_3.txt", "r") as f:
	for i in f:
		m13.append(float(i))
with open("main1_1.txt", "r") as f:
	for i in f:
		m21.append(float(i))
with open("main1_2.txt", "r") as f:
	for i in f:
		m22.append(float(i))
with open("main1_3.txt", "r") as f:
	for i in f:
		m23.append(float(i))
with open("main2_1.txt", "r") as f:
	for i in f:
		m31.append(float(i))
with open("main2_2.txt", "r") as f:
	for i in f:
		m32.append(float(i))
with open("main2_3.txt", "r") as f:
	for i in f:
		m33.append(float(i))

plt.histogram(m1, label="Linear Imagem Pequena")
plt.title("Média = " + str(np.mean(m1))+" Desvio Padrão = "+ str(np.std(m1)))
plt.legend()
plt.labelx("Tempo (s)")
plt.labely("Frequência")
plt.show()
plt.savefig("linear_pequeno.png")

plt.clf()

plt.histogram(m12, label="Linear Imagem Média")
plt.title("Média = " + str(np.mean(m12))+" Desvio Padrão = "+ str(np.std(m12)))
plt.legend()
plt.labelx("Tempo (s)")
plt.labely("Frequência")
plt.show()
plt.savefig("linear_medio.png")

plt.clf()

plt.histogram(m13, label="Linear Imagem Grande")
plt.title("Média = " + str(np.mean(m13))+" Desvio Padrão = "+ str(np.std(m13)))
plt.legend()
plt.labelx("Tempo (s)")
plt.labely("Frequência")
plt.show()
plt.savefig("linear_grande.png")

plt.clf()

plt.histogram(m2, label="Thread Imagem Pequena")
plt.title("Média = " + str(np.mean(m2))+" Desvio Padrão = "+ str(np.std(m2)))
plt.legend()
plt.labelx("Tempo (s)")
plt.labely("Frequência")
plt.show()
plt.savefig("thread_pequeno.png")

plt.clf()

plt.histogram(m22, label="Thread Imagem Média")
plt.title("Média = " + str(np.mean(m22))+" Desvio Padrão = "+ str(np.std(m22)))
plt.legend()
plt.labelx("Tempo (s)")
plt.labely("Frequência")
plt.show()
plt.savefig("thread_medio.png")

plt.clf()

plt.histogram(m23, label="Thread Imagem Grande")
plt.title("Média = " + str(np.mean(m23))+" Desvio Padrão = "+ str(np.std(m23)))
plt.legend()
plt.labelx("Tempo (s)")
plt.labely("Frequência")
plt.show()
plt.savefig("thread_grande.png")

plt.clf()

plt.histogram(m3, label="Process Imagem Pequena")
plt.title("Média = " + str(np.mean(m3))+" Desvio Padrão = "+ str(np.std(m3)))
plt.legend()
plt.labelx("Tempo (s)")
plt.labely("Frequência")
plt.show()
plt.savefig("process_pequeno.png")

plt.clf()

plt.histogram(m32, label="Process Imagem Média")
plt.title("Média = " + str(np.mean(m32))+" Desvio Padrão = "+ str(np.std(m32)))
plt.legend()
plt.labelx("Tempo (s)")
plt.labely("Frequência")
plt.show()
plt.savefig("process_medio.png")

plt.clf()

plt.histogram(m33, label="Process Imagem Grande")
plt.title("Média = " + str(np.mean(m33))+" Desvio Padrão = "+ str(np.std(m33)))
plt.legend()
plt.labelx("Tempo (s)")
plt.labely("Frequência")
plt.show()
plt.savefig("process_grande.png")

plt.clf()
