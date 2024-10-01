from math import sqrt
import matplotlib.pyplot as plt

def lagkcorrelation(k, data, n):
	x_mean = sum(data[:n-1]) / (n-1)
	y_mean = sum(data[1:n]) / (n-1)
	numerator = sum([(data[i] - x_mean) * (data[i+k] - y_mean) for i in range(n-k)])
	denominator = sqrt(sum([(x - x_mean)**2 for x in data[:n-1]]) * sum([(y - y_mean)**2 for y in data[1:n]]))
	return numerator / denominator

data = []
for line in open('out/data.txt'):
	data.append(float(line))
n = len(data)
print("Number of data points:", n)
num_batches = 31

if (n // 4 < n // num_batches):
	print("Sample more data!")
	exit()
else:
	print("Sample size is sufficient.")

plot_data = []
for k in range(n // num_batches):
	plot_data.append(lagkcorrelation(k, data, n))

plt.plot(plot_data)
plt.xlabel('Lag k -->')
plt.ylabel('Correlation ratio -->')
plt.title('Correlogram')
plt.savefig('out/correlogram.png')
print("Correlogram saved as correlogram.png")
print("------------------------------------------------")

b = min(range(len(plot_data)), key=lambda i: abs(plot_data[i]))
print("Best batch size:", b, "with correlation ratio:", plot_data[b])

all_batches = []
for i in range(n // b):
	all_batches.append(data[i * b:(i+1) * b])
print("Number of all batches:", len(all_batches))
batches = all_batches[1:31]
print("Number of batches:", len(batches))

def averages(batches, batch_size):
	return [sum(batch) / batch_size for batch in batches]

Mean = sum(averages(batches, b)) / len(batches)
print("Mean:", Mean)
StdDev = sqrt(sum([(x - Mean)**2 for x in averages(batches, b)]) / len(batches))
print("Standard deviation:", StdDev)
print("Confidence interval: [", Mean - 1.96 * StdDev / sqrt(len(batches)), ",", Mean + 1.96 * StdDev / sqrt(len(batches)), "]")
print("------------------------------------------------")

b = min(range(len(plot_data) // 3 * 2), key=lambda i: abs(plot_data[i]))
print("Best batch size in 2/3 of correlogram:", b, "with correlation ratio:", plot_data[b])
all_batches = []
for i in range(n // b):
	all_batches.append(data[i * b:(i+1) * b])
limit = len(all_batches)
print("number of all batches:", limit)
num_batches = 5
while True:
	batches = all_batches[:num_batches]
	Mean = sum(averages(batches, b)) / len(batches)
	StdDev = sqrt(sum([(x - Mean)**2 for x in averages(batches, b)]) / len(batches))
	ConfIntWidth = 2 * 1.96 * StdDev / sqrt(len(batches))
	if (ConfIntWidth <= 0.1 * Mean):
		break
	num_batches = int((ConfIntWidth / (0.1 * Mean))**2 * num_batches)
	if num_batches > limit:
		print("Sample more data!")
		break
print("Number of batches:", num_batches, "(", len(batches), ")")
print("Mean time of a machine being broken:", Mean)
print("------------------------------------------------")

def calculate_integer_product(x, y):
	product = x * y
	if product.is_integer():
		return int(product)
	else:
		return int(product) + 1
observations = []
for batch in batches:
	for observation in batch:
		observations.append(observation)
print("Number of observations:", len(observations))
sorted_observations = sorted(observations)
print("95th percentile:", sorted_observations[calculate_integer_product(0.95, len(observations))])
