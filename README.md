# 数据结构学习笔记

用 C++ 刷 LeetCode，系统学习数据结构。每道题都是独立的 `.cpp` 文件，包含可运行的完整代码。

## 力扣刷题进度

| 分类 | 已完成 | 题目 |
|------|--------|------|
| 链表 - 快慢指针 | 3 | 876、19、141 |
| 链表 - 双指针 | 1 | 160 |
| 链表 - 合并/运算 | 2 | 21、2 |
| 链表 - 删除节点 | 2 | 203、83 |
| 链表 - 反转链表 | 1 | 206 |
| 数组 - 杨辉三角 | 1 | 118 |

**力扣：10 题**

---

## 链表 (Linked List)

### 基础操作演示（非力扣题）

| 文件 | 内容 | 技巧 |
|------|------|------|
| `头插法_含new和malloc差异.cpp` | 头插法建链表 | 虚头节点 + 头插，含 `new` vs `malloc` 对比 |
| `尾插法_虚头节点.cpp` | 尾插法建链表 | 虚头节点 + 尾指针 |

### 快慢指针 (双指针)

| 题号 | 题目 | 文件 | 技巧 |
|------|------|------|------|
| [876](https://leetcode.cn/problems/middle-of-the-linked-list/) | 链表的中间节点 | `876链表的中间节点.cpp` | 快指针走两步、慢指针走一步，快指针到末尾时慢指针指向中点 |
| [19](https://leetcode.cn/problems/remove-nth-node-from-end-of-list/) | 删除链表的倒数第 N 个节点 | `19删除链表的倒数第n个节点_快慢指针.cpp` | 快指针先走 n 步，快慢再同步走；虚头节点避免处理头删边界 |
| [141](https://leetcode.cn/problems/linked-list-cycle/) | 环形链表 | `141环形链表.cpp` | 快慢指针，有环则必定相遇 |

### 双指针

| 题号 | 题目 | 文件 | 技巧 |
|------|------|------|------|
| [160](https://leetcode.cn/problems/intersection-of-two-linked-lists/) | 相交链表 | `023相交链表.cpp` | 两指针分别走 A→B 和 B→A，路径长度对齐后必在交点相遇 |

### 删除节点

| 题号 | 题目 | 文件 | 技巧 |
|------|------|------|------|
| [203](https://leetcode.cn/problems/remove-linked-list-elements/) | 移除链表元素 | `203移除链表元素.cpp` | 虚头节点 + 单指针判断 `temp->next`，删除后不动、没删才后移 |
| [83](https://leetcode.cn/problems/remove-duplicates-from-sorted-list/) | 删除排序链表中的重复元素 | `83删除排序链表中重复元素.cpp` | 排序链表去重不需虚头，直接比较 `temp->val` 和 `temp->next->val` |

### 反转链表

| 题号 | 题目 | 文件 | 技巧 |
|------|------|------|------|
| [206](https://leetcode.cn/problems/reverse-linked-list/) | 反转链表 | `206反转链表.cpp` | 头插法反转：遍历原链表，逐个创建新节点插入虚头之后 |

### 合并 / 运算

| 题号 | 题目 | 文件 | 技巧 |
|------|------|------|------|
| [21](https://leetcode.cn/problems/merge-two-sorted-lists/) | 合并两个有序链表 | `21合并两个有序链表.cpp` | 虚头节点 + 双指针遍历比较，剩余链表直接拼接 |
| [2](https://leetcode.cn/problems/add-two-numbers/) | 两数相加 | `2两数相加.cpp` | 链表模拟加法，`bool` 做进位标记，`l1 \|\| l2 \|\| IsCarry` 处理不等长和最后进位 |

---

## 数组 (Vector)

### 基础操作演示（非力扣题）

| 文件 | 内容 | 技巧 |
|------|------|------|
| `vector.cpp` | vector 基础操作 | 初始化（列表/拷贝/memset）、增删（push_back/insert/pop_back/erase）、访问（at vs []） |

### 杨辉三角

| 题号 | 题目 | 文件 | 技巧 |
|------|------|------|------|
| [118](https://leetcode.cn/problems/pascals-triangle/) | 杨辉三角 | `118杨辉三角.cpp` | `vector<vector<int>>` 二维数组，`resize` 预分配 + 直接索引，或 `push_back` 逐行构建 |

---

## 常用技巧总结

| 技巧 | 应用场景 | 相关题目 |
|------|----------|----------|
| **虚头节点 (Dummy Head)** | 简化头节点边界处理，避免判空 | 全部题目 |
| **快慢指针** | 找中点、找倒数第 k 个、判环 | 876、19、141 |
| **尾指针** | 尾插法构建链表，O(1) 追加 | 尾插法、21 |
| **头插法反转** | 遍历原链表，逐个摘下节点插入新链表头部 | 206 |

---

## 项目结构

```
LinkedList/
├── SingleList/          # 单链表（当前主力）
│   ├── SingleList.sln
│   └── *.cpp            # 力扣题 + 基础演示
└── DoublyLinkedList/    # 双向链表（新建，暂无题目）
    ├── DoublyLinkedList.sln
    └── *.cpp
Stack-Queue/              # 栈和队列
├── Stack.sln              # VS 栈项目
├── *.cpp                  # 栈基础演示 + 应用题
└── Queue/                 # 队列子项目
    ├── Queue.sln          # VS 队列项目
    └── *.cpp              # 队列基础演示 + 应用题
Array(vector)/            # 数组/vector
├── Array(vector).sln     # VS 项目
└── *.cpp                 # vector 基础演示 + 力扣题
```

## 环境

- **IDE**: Visual Studio 2022 (v143)
- **语言**: C++17
- **远程**: [GitHub](https://github.com/wenshuo-zh/DataStructure-Notes)
