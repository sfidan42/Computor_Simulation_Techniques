from math import sqrt
import matplotlib.pyplot as plt

def lagkcorr(k, data, n):
	x_mean = sum(data[:n-1]) / (n-1)
	y_mean = sum(data[1:n]) / (n-1)
	numerator = sum([(data[i] - x_mean) * (data[i+k] - y_mean) for i in range(n-k)])
	denominator = sqrt(sum([(x - x_mean)**2 for x in data[:n-1]]) * sum([(y - y_mean)**2 for y in data[1:n]]))
	return numerator / denominator

data = []
for line in open('data.txt'):
	data.append(float(line))
n = len(data)

plot_data = []
for k in range(n // 4):
	plot_data.append(lagkcorr(k, data, n))

plt.plot(plot_data)
plt.xlabel('Lag k -->')
plt.ylabel('Correlation ratio -->')
plt.title('Correlogram')
plt.savefig('correlogram.png')
