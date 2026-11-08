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
# import numpy as np
# import matplotlib.pyplot as plt
# x1=np.linspace(0,2*np.pi,1000)
# y1=np.sin(x1)+x1**2
# x2=np.linspace(-2,2,1000)
# y2=x2**3+2*x2**2+1
# plt.figure(figsize=(10,4))
# plt.subplot(1,2,1)#分成1行，2列，在第一个图
# plt.plot(x1,y1,color="#2F83C0")
# plt.title(r"$f(x)=\sin x + x^2,\quad x\in[0,2\pi]$")
# plt.grid(True,alpha=0.4)
# plt.xlabel("x")
# plt.ylabel("f(x)")
# plt.subplot(1,2,2)
# plt.plot(x2,y2,color="#ff7f0e")
# plt.title=(r"$f(x)=x^3 + 2x^2 + 1,\quad x\in[-2,2]$")
# plt.grid(True, alpha=0.4)
# plt.xlabel("x")
# plt.ylabel("f(x)")
# plt.tight_layout()
# plt.show()
#202519019 梁欣



import numpy as np
import matplotlib.pyplot as plt

# ---------------------- 数据定义 ----------------------
# 每行：A/B/C产品；每列：原料费、人工费、管理费（万元/件）
unit_cost = np.array([
    [0.6, 1.8, 0.9],
    [1.8, 2.4, 1.5],
    [0.6, 1.2, 0.9]
])

# 产量：行A/B/C，列：一季度、二季度、三季度、四季度（件）
output = np.array([
    [4000, 4500, 4500, 4000],
    [2000, 2600, 2400, 2200],
    [5800, 6200, 6000, 5000]
])

# 三维数组：[产品，季度，成本类型]，每个单元格=产量*单件成本
cost_detail = output[:, :, np.newaxis] * unit_cost[:, np.newaxis, :]

# ---------------------- (1) 四个季度总成本总和 ----------------------
total_all = cost_detail.sum()
print(f"(1) 四个季度总成本总和：{total_all:.2f} 万元")

# ---------------------- (2) 第一季度总成本 ----------------------
q1_total = cost_detail[:, 0, :].sum()
print(f"(2) 第一季度总成本：{q1_total:.2f} 万元")

# ---------------------- (3) 每个季度【原料、人工、管理】成本，写入csv ----------------------
# 在产品维度求和，得到 shape=(4,3)  4个季度，3类成本
quarter_cost = cost_detail.sum(axis=0)
print("(3) 各季度原料费、人工费、管理费：")
print(quarter_cost)
# 写入csv，逗号分隔
np.savetxt("cost_product.csv", quarter_cost, fmt="%.2f", delimiter=",")
print("✅ 数据已写入 cost_product.csv")

# ---------------------- (4)(5) 绘制子图 ----------------------
plt.rcParams['font.sans-serif'] = ['SimHei']  # Windows用黑体，Linux替换成WenQuanYi Zen Hei
plt.rcParams['axes.unicode_minus'] = False

fig, (ax1, ax2) = plt.subplots(1, 2, figsize=(13, 5))
quarter_name = ["一季度", "二季度", "三季度", "四季度"]

# 子图1：折线图，产量趋势
ax1.plot(quarter_name, output[0], marker='o', label="A")
ax1.plot(quarter_name, output[1], marker='o', label="B")
ax1.plot(quarter_name, output[2], marker='o', label="C")
ax1.set_xlabel("季度")
ax1.set_ylabel("产量")
ax1.set_title("A、B、C三种产品季度产量变化趋势")
ax1.legend()
ax1.grid(alpha=0.3)

# 子图2：饼图，第一季度三类成本占比
q1_cost_type = cost_detail[:, 0, :].sum(axis=0)
pie_label = ["原料", "人工", "管理"]
ax2.pie(q1_cost_type, labels=pie_label, autopct="%.2f%%", startangle=90)
ax2.set_title("第一季度各项成本占比")

plt.tight_layout()
plt.show()
#202519019 梁欣