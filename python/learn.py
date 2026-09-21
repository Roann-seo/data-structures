#判断回文字符串
# str=input("请输入字符串:")
# if str==str[::-1]:
#     print(str+"是回文串")
# else:
#     print(str+"不是回文串")



#输入三条边边长，当输入正确时计算三角形面积
# import math
# a=float(input("请输入三角形边长a:"))
# b=float(input("请输入三角形边长b:"))
# c=float(input("请输入三角形边长c:"))
# if a+b>c and a+c>b and b+c>a:
#     h=(a+b+c)/2;
#     area=math.sqrt(h*(h-a)*(h-b)*(h-c))
#     print("三角形面积为:{:.2f}".format(area))
# else :
#     print("用户输入有误")


#计算BMI
# weight=float(input("请输入一个人的体重："))
# height=float(input("请输入一个人的身高:"))
# BMI=weight/(height*height)
# if BMI<18.5:
#     print("过轻")
# elif (BMI<23.9):
#     print("正常")
# elif BMI<27.9:
#     print("过重")
# elif BMI<32:
#     print("肥胖")
# else:
#     print("过于肥胖")



#输入一个三位数的正整数中最大的一维数字是多少
# num=int(input("请输入一个三位数"))
# a=num//100
# b=num%100//10
# c=num%100%10
# if a>b:
#     if a>c:
#         print(f"最大值为:{a}")
#     else:
#         print(f"最大值为:{c}")
# else:
#     if(b>c):
#         print(f"最大值为:{b}")
#     else:
#         print(f"最大值为:{c}")



#统计英文句子中的大小写单词和数字
# str=input("请输入一段英文句子:")
# upper=0
# lower=0
# digit=0
# for s in str:
#     if s.isupper():
#         upper=upper+1
#     if s.islower():
#         lower=lower+1
#     if s.isdigit():
#         digit=digit+1
# print(f"大写字母：{upper}"
#         f"小写字母：{lower}"
#         f"数字:{digit}")



#求1-100中所有整数的和
sum=0
for i in range(1,100+1):
    sum=sum+i
print(f"sum={sum}")
