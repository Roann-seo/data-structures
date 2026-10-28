# 一个数如果恰好等于它的因子之和，这个数就称为“完数”。例如6=1＋2＋3.编程
# 　　　找出1000以内的所有完数。

# for n in range(2,1001):#n从2遍历到1000
#     sum=0
#     for i in range(1,n):#i从1取到n-1
#         if n%i==0:
#             sum+=i
#     if sum==n:
#         print(n)
# #202519019梁欣


# 打印出所有的“水仙花数”，所谓“水仙花数”是指一个三位数，其各位数字立方和等于该数本身。
# 例如：153是一个“水仙花数”，因为153=1的三次方＋5的三次方＋3的三次方。
# for n in range(100,1000):
#     hundred=n//100
#     ten=n%100//10
#     one=n%100%10
#     if hundred*hundred*hundred+ten*ten*ten+one*one*one==n:
#         print(n)
#202519019梁欣

# 输入一行字符，分别统计出其中英文字母、空格、数字和其它字符的个数。
# 输入一行字符，分别统计出其中英文字母、空格、数字和其它字符的个数。
# 输入一行字符，分别统计出其中英文字母、空格、数字和其它字符的个数。
# s1 = input("请输入一段字符:")

# letter = 0   #英文字母
# space = 0    #空格
# digit = 0    #数字
# other = 0    #其他字符

# for c in s1:
#     if c.isalpha():
#         letter += 1
#     elif c.isspace():
#         space += 1
#     elif c.isdigit():
#         digit += 1
#     else:
#         other += 1

# print(f"字母：{letter}")
# print(f"空格：{space}")
# print(f"数字：{digit}")
# print(f"其他字符：{other}")



#输出100～200间的全部素数，每行输出10个数。
count=0
for n in range(100,201):
    flag=1
    for i in range (2,n):
        if n%i==0:
            flag=0#说明不是素数
            break;
    if flag==1:
        print(n,end=" ")
        count+=1
        if count%10==0:
            print()
#202519019梁欣