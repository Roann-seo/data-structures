# list=[1,2,3,4,5]
# print(list)
# list[0]=2
# print(list)
# list.append(6)
# print(list)
# list.insert(0,7)#前面代表在第几个位置插入，后面表示插入几
# print(list)
# #列表扩充
# list2=[6,7,8,9]
# print(list+list2)
# list.extend(list2)
# print(list)
# print(list*2)
# #删除列表
# del(list[0])
# print(list)
# list.pop(0)#这个括号里面填索引位置
# print(list)
# list.remove(list[2])#这个括号里面填要删除的值
# print(list)
# #其他应用操作
# print(len(list))
# print(1 in list)
# print(1 not in list)
# list5=[1,2,3,4]
# a=list5.index(3)
# print(a)
# list6=[2,2,2,3,4,5]
# print(list6.count(2))
# #列表遍历
# for i in list:
#     print(i)
# for i in range(len(list)):
#     print(i,list[i])#遍历下表，range不能单独放在in后面
# #列表排序
# list2=[3,2,5,6]
# #list2.sort()
# #print(list2)
# newsort=sorted(list2)
# print(newsort)#生成一个排好序的列表，不会改动原来的列表
# #列表的复制
# list3=list2#是别名 完全公用一块内存
# print(list3)
# list4=list2.copy()#浅拷贝，共享空间，修改list2,list4不会跟着变
# print(list4)
# #删除
# list2.clear()
# print(list2)
# del(list3)
# #202519019 梁欣



#从键盘输入10个整数，放入列表中，
#将该列表转化为元组，输出该元组的元素个数，最大值，最小值，元素和，平均值。
# lst=[]
# for i in range (10):
#     num=eval(input("请输入一个整数"))
#     lst.append(num)
# print(lst)
# t=tuple(lst)
# print(t)
# print(f"元素个数{len(t)}")
# print(f"最大值{max(t)}")
# print(f"最小值{min(t)}")
# print(f"元素和{sum(t)}")
# print(f"平均值{sum(t)/len(t)}")
#202519019 梁欣


# 3.系统里有多个用户，用户信息目前保存在列表里，代码如下：
# users=[‘root’, ’test’]
# passwds=[‘123’, ‘456’]
# 依据以下流程写程序判断用户登录是否成功。
# （1）判断用户是否存在。
# （2）如果用户存在，判断用户密码是否正确。先找出用户对应的索引值，
# 根据passwds索引值找到该用户的密码。如果密码正确则登录成功，退出循环；
# 如果密码不正确，则重新登录，共有三次登录机会。
# （3）如果用户不存在，则重新登录，共有三次登录机会。
users=['root','test']
passwds=['123','456']
for i in range(3):
    username=(input("请输入用户名:"))
    if username in users:
        idx=users.index(username)
        pwd=input("请输入密码:")
        if(pwd==passwds[idx]):
            print("登录成功")
            break
        else:
            print("密码错误")
            if i==2:
                print("三次机会用完，登陆失败")
    else:
        print("用户名不存在")
        if i==2:
            print("三次机会用完，登陆失败")
#201519019 梁欣