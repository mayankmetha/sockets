import matplotlib.pyplot as plt
import sys

x = []
y = []

for line in sys.stdin:
    x.append(int(line.split(",")[0]))
    y.append(float(line.split(",")[1]))

plt.plot(x,y)
plt.xlabel('Message number')
plt.ylabel('Response time in ms')
plt.title("Response Time Analysis")
plt.show()