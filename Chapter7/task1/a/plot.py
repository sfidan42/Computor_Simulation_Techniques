from matplotlib import pyplot as plt

nums_customers = []
waiting_times = []

for i in range(10):
    file_path = f'out/data_{i}.txt'
    with open(file_path, 'r') as file:
        lines = file.readlines()
        if len(lines) >= 2:
            nums_customers.append(int(lines[0].strip()))
            waiting_times.append(float(lines[1].strip()))

plt.plot(nums_customers, waiting_times)
plt.xlabel("Queue Capacity")
plt.ylabel("Waiting Time")
plt.title("Plot of Waiting Times vs Queue Capacity")
plt.savefig("out/wait_vs_cap.png")
