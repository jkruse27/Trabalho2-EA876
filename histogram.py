import matplotlib.pyplot as plt
import numpy as np
from scipy import stats
import os

DIR="Graficos/"

for i in os.listdir("."):
	if(".txt" in i):
		m = []
		with open(i, "r") as f:
			for j in f:
				try:
					m.append(float(j))
				except:
					pass
		mu=np.mean(m)
		sigma=np.std(m)
		plt.hist(m,bins=5, label="Média = %3f | Desvio Padrão = %3f" %(mu, sigma))
		x = np.linspace(mu - 3*sigma, mu + 3*sigma, 100)
		plt.plot(x, stats.norm.pdf(x, mu, sigma))
		plt.title(i.replace(".txt", ""))
		plt.legend()
		plt.xlabel("Tempo (s)")
		plt.ylabel("Frequência")
		plt.show()
		plt.savefig((DIR+i.replace("txt", "png")))

		plt.clf()
