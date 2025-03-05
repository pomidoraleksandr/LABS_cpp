import matplotlib.pyplot as plt
import pandas as pd
import numpy as np
data = pd.read_csv('l_search_avg.txt', sep = ' ')
N= data['number']
T=data['count']
plt.ylim()
plt.scatter(N, T,  color='green', label='TL(N)')
plt.xlabel('Элементов в массиве')
plt.ylabel('Время выполнения ')
plt.title('Линейный поиск(средний)')
plt.grid()
plt.legend()
plt.show()