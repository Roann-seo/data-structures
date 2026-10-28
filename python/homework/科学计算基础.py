# 1.利用numpy库，创建两个ndarray数组A和B，两个数组的shape均为4X5，数组A的元素
# [[ 0, 1, 2, 3, 4],
#  [ 5, 6, 7, 8, 9],
#  [10, 11, 12, 13, 14],
#  [15, 16, 17, 18, 19]]，
# 数组B的元素为：[[100, 101, 102, 103, 104],
#       		 [105, 106, 107, 108, 109],
#                [110, 111, 112, 113, 114],
#                [115, 116, 117, 118, 119]]。
# 编写程序实现以下功能：
# （1）输出A+B、B-A、A*B、A/B、A2+B3的结果。
# （2）对A的中间两行和B的中间两行的元素进行求和，并输出。
# （3）输出A的数组轴个数rank、数组形状shape、数组大小和数组中每个元素占用的字节数。
# import numpy as np
# arr=np.array([[ 0, 1, 2, 3, 4],
#     [ 5, 6, 7, 8, 9],
#     [10, 11, 12, 13, 14],
#     [15, 16, 17, 18, 19]])
# brr=np.array([[100, 101, 102, 103, 104],
#     [105, 106, 107, 108, 109],
#     [110, 111, 112, 113, 114],
#     [115, 116, 117, 118, 119]])

# print(f"A+B={arr+brr}")
# print(f"B-A={brr-arr}")
# print(f"A*B={arr*brr}")
# print(f"A/B={arr/brr}")
# print(f"A2+B3={arr[2]+brr[3]}")
# temp=arr[1]+arr[2]+brr[1]+brr[2]#得到的是numpy的一维数组，不是单个数字
# total=temp.sum()#对一维数组求和
# print(f"A的中间两行和B的中间两行的元素求和={total}")
# print("A数组的秩:",arr.ndim)
# print("A数组的形状:",arr.shape)
# print("A数组的大小:",arr.size)
# print("A每个元素占用字节数:",arr.itemsize)
# #202519019 梁欣



# 2.绘制下列函数的图形：
# 	1）\(f(x)=\sin x + x^2,\ x\in[0,2\pi]\)
# （2）\(f(x)=x^3 + 2x^2 + 1,\ x\in[-2,2]\)
import numpy as np
import matplotlib.pyplot as plt
x1=np.linspace(0,2*np.pi,1000)
y1=np.sin(x1)+x1**2
x2=np.linspace(-2,2,1000)
y2=x2**3+2*x2**2+1
plt.figure(figsize=(10,4))
plt.subplot(1,2,1)#分成1行，2列，在第一个图
plt.plot(x1,y1,color="#1f77b4")
plt.title(r"$f(x)=\sin x + x^2,\quad x\in[0,2\pi]$")
plt.grid(True,alpha=0.4)
plt.xlabel("x")
plt.ylabel("f(x)")
plt.subplot(1,2,2)
plt.plot(x2,y2,color="#ff7f0e")
plt.title=(r"$f(x)=x^3 + 2x^2 + 1,\quad x\in[-2,2]$")
plt.grid(True, alpha=0.4)
plt.xlabel("x")
plt.ylabel("f(x)")
plt.tight_layout()
plt.show()
#202519019 梁欣