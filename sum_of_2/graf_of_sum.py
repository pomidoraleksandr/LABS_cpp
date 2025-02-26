import matplotlib.pyplot as plt
#N=[500,1000, 5000,15000,50000,150000,250000,500000, 750000,1000000]
#T=[2,5, 22, 68, 254,726,1203, 2576, 3666, 4501]
X=[10, 20, 50,75, 150, 200, 375, 500]
Y=[17, 57, 326, 696, 2802,4784, 16820, 29675]
#plt.plot(N, T,  color='blue', label='Fast_sum')
plt.plot(X, Y, color='green', label='Long_sum')
plt.xlabel('Элементов в массиве')
plt.ylabel('Время выполнения x10^5')
plt.title('Slow alg')
plt.grid()
plt.legend()
plt.show()