import matplotlib.pyplot as plt
import pandas as pd
import numpy as np
data = pd.read_csv('b_search_max.txt', sep = ' ')
N= data['number']
T=data['count']
plt.ylim(150,320)
plt.scatter(N, T,  color='red', label='TB(N)')
plt.xlabel('Элементов в массиве')
plt.ylabel('Время выполнения ')
plt.title('Бинарный поиск(максимальный)')
plt.grid()
plt.legend()
plt.show()
