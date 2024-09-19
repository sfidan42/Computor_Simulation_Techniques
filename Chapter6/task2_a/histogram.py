import csv

with open('out/data.csv') as f:
    import matplotlib.pyplot as plt

    reader = csv.reader(f)
    next(reader)  # Skip header row
    arrivals = []
    departures = []

    for row in reader:
        arrivals.append(float(row[0]))
        departures.append(float(row[1]))

    plt.figure(figsize=(10, 5))

    plt.subplot(1, 2, 1)
    plt.hist(arrivals, bins=20, color='blue', alpha=0.7)
    plt.title('Arrival Time')
    plt.xlabel('Time')
    plt.ylabel('Frequency')

    plt.subplot(1, 2, 2)
    plt.hist(departures, bins=20, color='green', alpha=0.7)
    plt.title('Departure Time')
    plt.xlabel('Time')
    plt.ylabel('Frequency')

    plt.tight_layout()
    plt.savefig('out/ArrDepHist.png')
    plt.close()

    print("mean arrival time:", sum(arrivals) / len(arrivals))
    print("mean departure time:", sum(departures) / len(departures))