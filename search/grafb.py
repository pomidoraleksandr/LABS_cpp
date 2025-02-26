import matplotlib.pyplot as plt
N=[100, 250, 500, 1000, 5000, 10000, 50000, 100000, 500000, 750000, 1000000]
T=[20, 68, 143, 286, 1302, 2582, 13500, 26200, 123600, 171500, 217400]

plt.plot(N, T,  color='red', label='TB(N)')
plt.xlabel('Элементов в массиве')
plt.ylabel('Время выполнения x10^5')
plt.title('Бинарный поиск')
plt.grid()
plt.legend()
plt.show()