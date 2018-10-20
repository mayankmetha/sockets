import matplotlib.pyplot as plt
import csv
import sys

x = []
y = []

with open(sys.argv[1],"r") as csvFile:
    plots = csv.reader(csvFile,delimiter=",")
    for row in plots:
        x.append(int(row[0]))
        y.append(float(row[1]))

plt.plot(x,y)
plt.xlabel('Message number')
plt.ylabel('Response time in ms')
plt.title("Response Time Analysis")
plt.show()