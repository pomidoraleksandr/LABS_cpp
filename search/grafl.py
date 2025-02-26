import matplotlib.pyplot as plt

N=[100, 250, 500, 1000, 5000, 10000, 50000, 100000, 500000, 750000, 1000000]
T=[41, 92, 181, 348, 1698, 3359, 16100, 33100, 157600, 231000, 297700]

plt.plot(N, T,  color='red', label='TL(N)')
plt.xlabel('Элементов в массиве')
plt.ylabel('Время выполнения x10^5')
plt.title('Линейный поиск')
plt.grid()
plt.legend()
plt.show()