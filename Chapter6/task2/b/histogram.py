import csv

with open('out/data.csv') as f:
    import matplotlib.pyplot as plt

    reader = csv.reader(f)
    next(reader)  # Skip header row
    arrivals = []
    departures = []
    starts = []
    services = []

    for row in reader:
        arrivals.append(float(row[0]))
        starts.append(float(row[1]))
        departures.append(float(row[2]))
        services.append(float(row[3]))

    plt.figure(figsize=(10, 5))

    plt.subplot(2, 2, 1)
    plt.hist(arrivals, bins=20, color='blue', alpha=0.7)
    plt.title('Arrival Time')
    plt.xlabel('Time')
    plt.ylabel('Frequency')

    plt.subplot(2, 2, 2)
    plt.hist(departures, bins=20, color='green', alpha=0.7)
    plt.title('Departure Time')
    plt.xlabel('Time')
    plt.ylabel('Frequency')

    plt.subplot(2, 2, 3)
    plt.hist(starts, bins=20, color='red', alpha=0.7)
    plt.title('Waiting Time')
    plt.xlabel('Time')
    plt.ylabel('Frequency')

    plt.subplot(2, 2, 4)
    plt.hist(services, bins=20, color='yellow', alpha=0.7)
    plt.title('Service Time')
    plt.xlabel('Time')
    plt.ylabel('Frequency')

    plt.tight_layout()
    plt.savefig('out/ArrDepStartServHist.png')
    plt.close()

    print("mean arrival time:", sum(arrivals) / len(arrivals))
    print("mean departure time:", sum(departures) / len(departures))
    print("mean waiting time:", sum(starts) / len(starts))
    print("mean service time:", sum(services) / len(services))