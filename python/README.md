# Python 学习目录（数据结构与算法方向）

> 前提：你已经有 C 和 C++ 基础。所以学 Python 不重学编程逻辑，只补两部分：
> 1. **Python 与 C/C++ 的差异**（语法糖）
> 2. **Python 自带的数据结构**（做算法最省力的地方）
>
> 然后立刻用 Python 重刷你已经在做的算法题，最快见效。

---

## 阶段 0：Python 与 C/C++ 差异速成（1~2 天）

跳过变量、循环、判断这些你已会的内容，只补 Python 特有的写法。

| 你会的 C/C++ | Python 对应 | 重点 |
|---|---|---|
| `int a[100]` / `vector` | `list` | 动态、可切片、可放任意类型 |
| 指针 `*p`、引用 `&` | 无（对象引用） | 传参是「引用语义」，但不可变对象表现不同 |
| `{}`、分号 | 缩进 + 冒号 | 缩进即代码块 |
| `for(int i=0;...)` | `for i in range(n)` / `for x in arr` | 优先遍历元素而非下标 |
| `int main()` | `if __name__ == "__main__":` | 入口写法 |
| `scanf` / `printf` | `input()` / `print()` / f-string | `f"{x}"` 格式化 |
| `++i`、三元 `?:` | 无 `++`；`a if cond else b` | 常见坑 |
| `#include` | `import` | `from collections import deque` |

> 这一步不求精通，见到能看懂即可。核心是**别拿 C 的思维硬写 Python**。

---

## 阶段 1：Python 内置数据结构（重点中的重点）⭐

这是 Python 做算法最大的优势，也是花时间最多的部分。

1. **list** —— 数组 + 栈 + 队列通用
   - 切片：`arr[1:3]`、`arr[::-1]`（反转）
   - 列表推导式：`[x*2 for x in arr if x > 0]`
   - `append` / `pop` / `insert` / `index`
2. **dict** —— 对应 C++ 的 `unordered_map`，哈希表
   - `d[key]`、`d.get(key, 默认值)`、`for k, v in d.items()`
   - 计数用 `collections.Counter`
3. **set** —— 对应 `unordered_set`，去重、判重 O(1)
4. **deque**（`collections`）—— 双端队列，栈和队列都用它，别用 list 当队列
5. **heapq** —— 堆 / 优先队列（注意默认是小顶堆）
6. **str / tuple** —— 不可变，字符串常用方法
7. **sorted / sort(key=)** —— 排序，`key` 参数是灵魂
8. **bisect** —— 二分查找、有序插入

> 学完这步，你会发现 C++ 里要写几十行的哈希表、堆、双指针，Python 一行就搞定。

---

## 阶段 2：用 Python 重刷「算法基础」

对应仓库 `算法/` 目录，把你已经会的 C/C++ 算法题用 Python 重写一遍，体会差异：

- 位运算（二进制中 1 的个数、异或、不同位数）
- 排序算法（插入排序 → Python 的 `sorted` 底层是 TimSort）
- 递归、二分查找
- 双指针、滑动窗口

---

## 阶段 3：数据结构专题

对应仓库 `数据结构学习/leetcode刷题/`，用 Python 重刷刷过的 LeetCode：

- 数组 / 链表 / 栈 / 队列
- 哈希表（`dict` / `set` 直接秒）
- 二叉树遍历（前中后序、层序）
- 图（BFS / DFS，`deque` + `set`）
- 堆、并查集

---

## 阶段 4：进阶（刷题实战）

- 动态规划（记忆化用 `functools.lru_cache`）
- 回溯（DFS）
- 贪心
- 常用库：`itertools`（排列组合）、`functools`、`math`

---

## 建议学习路径

```
阶段 0 → 阶段 1 → 阶段 2（重刷已会的算法题，最快见效）→ 阶段 3 → 阶段 4
```

从阶段 1 的 `list` / `dict` 开始，边学边用仓库里的题练手。

---

## 环境说明

- **解释器**：Python 3.13.5（`D:\Python313\python.exe`），VSCode 已装 Python / Pylance / debugpy 扩展。
- **运行方式**：打开 `.py` 文件，点右上角 ▶，或终端执行 `python 文件名.py`。
- 如果右下角解释器不对，`Ctrl+Shift+P` → **Python: Select Interpreter**，选 `D:\Python313\python.exe`。
