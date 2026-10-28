# 1. 已知字符串变量 s=”According to independent research conducted on behalf of the IOC,
# Beijing 2022 has become the most digitally engaged Olympic Winter Games in history,
# with 2.01 billion viewers, up 5% from PyeongChang 2018 watching the Games through 
# linear TV and digital platforms. Viewers watched a total of 713 billion minutes of 
# the Games coverage through Olympic media rights partners' channels, 
# and Olympic social media also achieved 3.2 billion engagements and attracted more 
# than 11 million new followers across various platforms.” 编写程序，实现以下功能：
# （1）对字符串中每个单词出现的次数进行统计，并将结果输出；
# （2）输出出现次数排在前五的单词
# s = """According to independent research conducted on behalf of the IOC,
# Beijing 2022 has become the most digitally engaged Olympic Winter Games in history,
# with 2.01 billion viewers, up 5% from PyeongChang 2018 watching the Games through
# linear TV and digital platforms. Viewers watched a total of 713 billion minutes of
# the Games coverage through Olympic media rights partners' channels, and Olympic
# social media also achieved 3.2 billion engagements and attracted more than 11
# million new followers across various platforms."""
# s=s.lower().replace(',',' ').replace('.',' ')
# words=s.split()
# count={}
# for w in words:
#     count[w]=count.get(w,0)+1
# print("单词输出:")
# for w,num in count.items():
#     #count.items()相当于把字典转成元组
#     print(w,num)
# top5=sorted(count.items(),key=lambda x:x[1],reverse=True)[:5]#去前五个
# #x表示里面的每一个元组 x[1]取元组的第二项（比较标准）
# print("前五个单词:")
# for w,num in top5:
#     print(w,num)
# #202519019 梁欣



# 2. 假设字典dic_city中存放了每个人旅游过的城市，内容为{“张三”:[“北京”,”成都”], 
# “李四”:[“上海”,”广州” ,”兰州”], “王五”:[“太原”,”西安” ,”济南” ,”上海”]}。
# 编写程序，实现以下功能：
# （1）统计每个人旅游过的城市的数目。输出结果如下：
# 张三去过2个城市
# 李四去过3个城市
# 王五去过4个城市
# （2）统计去过上海的人数以及名单。输出结果如下：
#      去过上海的有2人，他们是李四、王五
# zhangsan={"北京","成都"}#这个是集合，只有列表才有count，集合有len
# lisi={"上海","广州","兰州"}
# wangwu={"太原","西安","济南","上海"}
# print(f"张三去过{len(zhangsan)}个城市")
# print(f"李四去过{len(lisi)}个城市")
# print(f"王五去过{len(wangwu)}个城市")
# people={
#     "张三":zhangsan,
#     "李四":lisi,
#     "王五":wangwu
# }
# name_list=[]
# for name,city in people.items():
#     if "上海" in city:
#         name_list.append(name)
# print(f"去过上海的有{len(name_list)}人,他们是{','.join(name_list)}")
# #202519019 梁欣



# 现需对参赛人数进行统计。编写程序，实现以下功能：
# （1）使用集合变量set_highjump和set_longjump分别存储参加跳高和跳远比赛的学生姓名。
# （2）统计参加比赛的所有学生名单并输出；
# （3）统计两项比赛都参加的学生名单并输出；
# （4）统计仅参加跳高比赛的学生名单并输出；
# （5）统计仅参加跳远比赛的学生名单并输出；
# （6）统计仅参加一项比赛的学生名单并输出。

set_highjump={"李朋","王宇","张锁","刘松山","白旭","李晓亮"}
set_longjump={"王宇","唐英","刘松山","白旭","刘小雨","宁成"}
set_jump=set_highjump|set_longjump
print("参加比赛的所有学生名单")
for people in set_jump:
    print(people)
print("两项比赛都参加的学生名单")
set_bothjump=set_longjump&set_highjump
for people in set_bothjump:
    print(people)
set_onlyhighjump=set_highjump-set_longjump
print("仅参加跳高比赛的学生名单")
for people in set_onlyhighjump:
    print(people)
set_onlylongjump=set_longjump-set_highjump
print("仅参加跳远比赛的学生名单")
for people in set_onlylongjump:
    print(people)
set_onlyone=set_jump-set_bothjump
print("仅参加一项比赛的学生名单")
for people in set_onlyone:
    print(people)
#202519019 梁欣

# 1.列表 list[] lst=[1,2,3]
# Len(lst)求元素个数
# Lit.count(x)统计 x 在列表里出现多少次,只有列表有这个！
# Lst.append(x)末尾追加元素
# Lst.remove(x)删除第一个 x
# For i in lst遍历里面每一个值
# 2.集合set{}
# S={1,2,3}
# Len(s)求集合元素数量（集合没有 .count ()
# X in s判断 x 是否在集合里（查找速度很快）
# A|B  A 或者 B，合并去重（跳高或跳远）
# A&B  同时在 A 和 B（两项都参加）
# A-B  在 A，不在 B（只跳高不跳远）
# A^B  只在一边，不同时在两边
# S.add(x)添加元素
# S.remove(x)删除元素
# 空集合s=set(),不能写set{},{}是空字典
# 3.字典 dict{key:value}
# Len(d)键值对的个数
# D.get(key,默认值）：重点！ 取 key 对应的值，找不到 key 就返回默认值（单词计数 count.get(w,0)+1）
# D.Item()返回 (key,value) 元组序列，用来同时遍历键和值
# D.keys()只拿所有键；
# D.values()只拿所有值