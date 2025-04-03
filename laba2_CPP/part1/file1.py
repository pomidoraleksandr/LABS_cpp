import pandas as pd
import matplotlib.pyplot as plt
import math as mth
import numpy as np
import statistics
data = pd.read_csv("first.txt", sep=' ')
x = data['count']
y = data['time']
n = len(data['count'])
p = 54
k = 0
Y = list(map(lambda x: mth.log(x), y))
X = list(map(lambda x: mth.log(x), x))
Y2 = list(map(lambda x: x*x, Y))
x2 = list(map(lambda x:x *x, X))
def approx(X, Y):
    X1 = np.linspace(min(X), max(X), 100)
    z1=np.polyfit(X, Y, 1)
    print(z1[0],z1[1], 'K и B')
    Y1 =np.poly1d(z1)(X1)
    return Y1
appX = np.linspace(min(X[p:n]), max(X[p:n]), 100)
appY = approx(X[p:n], Y[p:n])
y_mean = statistics.mean(Y[p:n])
y2_mean = statistics.mean(Y2[p:n])
x_mean = statistics.mean(X[p:n])
x2_mean = statistics.mean(x2[p:n])
k_sigma = mth.sqrt((1/(len(x[p:n])-2))*mth.fabs(((y2_mean-y_mean**2)/(x2_mean-x_mean**2)-k**2)))
b_sigma = k_sigma*mth.sqrt(x2_mean)
print(k_sigma, b_sigma)
plt.scatter(X, Y, color = 'green', label = 'ln')
plt.plot(appX, appY,  color='red', label='k = 2,06')
#plt.ylim(0, 800000)
plt.xlabel("ln(N), число элементов")
plt.ylabel("ln(t), нс")
plt.title("Первая стратегия")
plt.legend()

plt.tight_layout()
plt.show()