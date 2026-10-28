# 1.编写程序找出符合以下要求的三位正整数：
# 分别乘以3、4、5、6、7后得到的整数的各位数字之和都相等。
# 其中计算某个正整数（不一定是三位整数）各位数字之和的过程定义成一个独立的函数实现。
# 输出示例如下：
# X=180: x*3=540, x*4=720, x*5=900, x*6=1080, x*7=1260
# X=198: x*3=594, x*4=792, x*5=990, x*6=1188, x*7=1386
# ……
# X=999: x*3=2997, x*4=3996, x*5=4995, x*6=5994, x*7=6993
# 共有21个符合条件的三位整数。
# def sum_digit(n):
#     s=0
#     while n>0:
#         s+=n%10
#         n=n//10
#     return s
# count=0
# for x in range(100,1000):
#     s3=sum_digit(x*3)
#     s4=sum_digit(x*4)
#     s5=sum_digit(x*5)
#     s6=sum_digit(x*6)
#     s7=sum_digit(x*7)
#     if s3==s4==s5==s6==s7:
#         print(f"X={x}:x*3={x*3},x*4={x*4},x*5={x*5},x*6={x*6},x*7={x*7}")
#         count+=1
# print(f"共有{count}个符合条件的三位数")
# #202519019 梁欣




# 2. 求s=a+aa+aaa+…+(aaa…aaa)的值，其中a是1-9之间的某个数字，n是一个正整数，
# 代表加和表达式的项数。例如当a=2, n=5时，s=2+22+222+2222+22222=24690. 
# 编写程序定义一个函数，该函数根据a 和n 的值计算并返回s的值，并在主程序中调用测试该函数。
# def calc_sum(a,n):
#     s=0
#     current=0
#     while n>0:
#         current=current*10+a
#         s+=current
#         n=n-1
#     return s
# print(f"sum={calc_sum(2,5)}")
# #202519019 梁欣



# 编写一个函数，接收一个列表参数，函数返回该列表中所有正数之和。在主程序中调用测试该函数。
def zheng_sum(lst):
    sum=0
    for i in lst:
        if i>0:
            sum+=i
    return sum
lst=[1,-2,3,-4,5,-6,7,8]
print(zheng_sum(lst))
#202519019 梁欣