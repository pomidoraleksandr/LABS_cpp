import matplotlib.pyplot as plt
import pandas as pd
import numpy as np
data = pd.read_csv('long_sum.txt', sep = ' ')
N= data['number']
T=data['count']
plt.ylim()
plt.scatter(N, T,  color='orange', label='T(N)')
plt.xlabel('Элементов в массиве')
plt.ylabel('Время выполнения, мс')
plt.title('Долгая сумма')
plt.grid()
plt.legend()
plt.show()