# 1.在windows下新建一个文本文件yzy.txt，文件内容如下：
# 慈母手中线，游子身上衣。
# 临行密密缝，意恐迟迟归。
# 谁言寸草心，报得三春晖。
# 编写程序读取并输出该文件的内容，要求使用一次性读取整个文件内容和逐行读取文件内容两种方式。
# with open("yzy.txt","w",encoding="utf-8") as f:
#     f.write("慈母手中线，游子身上衣。\n")
#     f.write("临行密密缝，意恐迟迟归。\n")       
#     f.write("谁言寸草心，报得三春晖。\n")       
# with open("yzy.txt","r",encoding="utf-8") as f:
#     content=f.read()
#     print(content)
# #一次性读取

# with open("yzy.txt","r",encoding="utf-8") as f:
#     while True:
#         line=f.readline()
#         if not line:#读到空字符串
#             break
#         print(line,end="")
#         #逐行读取，readline循环
#     #202519019 梁欣




# 2.编写程序新建一个文本文件yzy2.txt，并写入下面两行内容：
# 游子吟
# 唐代：孟郊
# 接着读取题目1中文件yzy.txt的内容，追加到文件yzy2.txt末尾，最后文件yzy2.txt的内容应该如下：
# 游子吟
# 唐代：孟郊
# 慈母手中线，游子身上衣。
# 临行密密缝，意恐迟迟归。
# 谁言寸草心，报得三春晖。
# with open("yzy2.txt","w",encoding="utf-8")as f:
#     f.write("游子吟\n")
#     f.write("唐代：孟郊\n")
# with open("yzy.txt","r",encoding="utf-8")as f:
#     content=f.read()
# with open("yzy2.txt","a",encoding="utf-8")as f:
#     f.write(content)
# with open("yzy2.txt","r",encoding="utf-8")as f:
#     line=f.read()
# print(line)
# #202519019 梁欣


# 3.在Windows环境下创建文件score.csv用来保存10名考生3门课程的成绩，内容如下：
# 考号,高级语言程序设计,高等数学,数据库原理
# 10153450101,72,96,88
# 10153450102,68,88,73
# 10153450103,63,63,66
# 10153450104,95,64,65
# 10153450105,89,88,57
# 10153450106,77,87,77
# 10153450107,67,64,97
# 10153450108,44,99,64
# 10153450109,82,73,75
# 10153450110,79,78,85
# 编写程序读取该文件内容，统计每门课程的平均分、最高分和最低分。
with open("score.csv","w",encoding="utf-8")as f:
    f.write("考号,高级语言程序设计,高等数学,数据库原理\n")
    f.write("10153450101,72,96,88\n")
    f.write("10153450102,68,88,73\n")
    f.write("10153450103,63,63,66\n")
    f.write("10153450104,95,64,65\n")
    f.write("10153450105,89,88,57\n")
    f.write("10153450106,77,87,77\n")
    f.write("10153450107,67,64,97\n")
    f.write("10153450108,44,99,64\n")
    f.write("10153450109,82,73,75\n")
    f.write("10153450110,79,78,85\n")
with open("score.csv","r",encoding="utf-8")as f:
    lines=f.readlines()
lang=[]
math=[]
db=[]
for line in lines[1:]:
    line=line.strip()#去掉换行空格
    part=line.split(",")#将字符串改为列表
    s1=int(part[1])#part[0]是学号
    s2=int(part[2])
    s3=int(part[3])
    lang.append(s1)
    math.append(s2)
    db.append(s3)
def stat(scores):
    avg=sum(scores)/len(scores)
    mx=max(scores)
    mn=min(scores)
    return avg,mx,mn
avg1,max1,min1=stat(lang)
avg2,max2,min2=stat(math)
avg3,max3,min3=stat(db)
print("====高级语言程序设计====")
print(f"平均分：{avg1:.2f},最高分:{max1:.2f},最低分:{min1:.2f}")
print("====高等数学====")
print(f"平均分：{avg2:.2f},最高分:{max2:.2f},最低分:{min2:.2f}")
print("====数据库原理====")
print(f"平均分：{avg3:.2f},最高分:{max3:.2f},最低分:{min3:.2f}")
#202519019 梁欣