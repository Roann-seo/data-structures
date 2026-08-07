# 数据结构（C 语言实现）

使用 C 语言实现常用数据结构及考研经典算法题。

## 目录

### 基础实现

- [线性表的顺序存储](1.线性表的顺序存储.c) — 顺序表初始化、增删改查
- [单链表](2.链表.c) — 链表初始化、头插法、尾插法、指定位置插入、遍历

### 单链表应用题

- [查找倒数第 k 个结点](3.单链表应用.c) — **（2019 考研）** 双指针法，时间复杂度 O(n)，空间复杂度 O(1)
- [两个链表的公共后缀](4.单链表应用.c) — 尾部对齐 + 同步比较结点地址，找公共后缀起始结点
- [删除绝对值重复的结点](5.单链表应用.c) — **（2015 考研）** 空间换时间，时间复杂度 O(n)，空间复杂度 O(n)

## 编译运行

```bash
# 基础实现
gcc "1.线性表的顺序存储.c" -o seqlist.exe -std=c11 -fexec-charset=UTF-8
gcc "2.链表.c" -o linkedlist.exe -std=c11 -fexec-charset=UTF-8

# 应用题
gcc "3.单链表应用.c" -o app3.exe -std=c11 -fexec-charset=UTF-8
gcc "4.单链表应用.c" -o app4.exe -std=c11 -fexec-charset=UTF-8
gcc "5.单链表应用.c" -o app5.exe -std=c11 -fexec-charset=UTF-8
```

或在 VS Code 中使用 Code Runner 直接运行。
