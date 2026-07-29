# CLAUDE.md

This file provides guidance to Claude Code (claude.ai/code) when working with code in this repository.

## Overview

Personal C++ data structures practice repo. Content is in Chinese (comments, variable names, `cout` messages). Currently focused on singly linked lists — expanding to other structures over time.

Remote: `https://github.com/wenshuo-zh/DataStructure-Notes.git`

## Build System

- **Environment**: Visual Studio 2022, Windows 11, v143 toolset (C++17+)
- **Solution**: `LinkedList/SingleList/SingleList.sln`
- **Configuration**: Debug x64 (default); Release x64 also available
- **Critical**: Every `.cpp` file in the project defines its own `main()` (or `struct ListNode` + `class Solution`). **Only one `.cpp` file can be compiled at a time.** To switch exercises in VS: right-click the unwanted `.cpp` files → Properties → "Excluded From Build" → Yes. Keep only the one you want active.
- **Build output**: `LinkedList/SingleList/x64/Debug/SingleList.exe`

## Repository Structure

```
.gitignore                  # VS/C++ build artifacts, .vs/, x64/, *.ipch, etc.
LinkedList/SingleList/      # Active project — singly linked list exercises
  SingleList.sln            # VS solution — open this
  SingleList.vcxproj        # MSBuild project (v143, console app, Debug/Release x64+Win32)
  *.cpp                     # Self-contained exercises (one per LeetCode problem)
回放/                       # Screen recordings (.vep), not tracked in git
```

## Coding Conventions

**文件名带数字题号的就是力扣题**，遵循 LeetCode 风格；不带的（如头插法、尾插法）是基础操作演示，保留 C 风格即可。

### 力扣题（文件名含题号，如 `203移除链表元素.cpp`）

**只写算法，可直接粘贴到 LeetCode 提交。不要 `#include`、不要 `using namespace`、不要 `main()`、不要 `delete` 释放内存。**

```cpp
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ReturnType methodName(ListNode* head, ...) {
        // 算法逻辑
    }
};
```

- 只有 `struct ListNode` + `class Solution`，其余一律不加
- 中文注释可以保留
- 不释放 `dummyHead`（LeetCode 会统一管理内存）

### 基础操作演示（文件名不含题号，如 `头插法_含new和malloc差异.cpp`）

- C 风格 `struct Node { int val; Node* next; }`，可带 `typedef`
- `createList()` / `printList()` / `freeList()` + `main()` 自驱动
- 保留教学注释（如 `new` vs `malloc` 的区别）
- 同样用 `new`/`delete`，不用 `malloc`/`free`

### 共用规则

- 中文注释解释算法步骤
- 中文 `cout` 输出
- 虚头节点 (dummy head) 简化边界处理

## Notes

- The `.vcxproj` file lists registered `.cpp` files. When adding a new exercise:
  1. Add the `.cpp` to `LinkedList/SingleList/`
  2. In VS: right-click Source Files → Add → Existing Item, or manually edit the `.vcxproj` `<ClCompile>` list
  3. Exclude all other `.cpp` files from build so only the new one compiles
- `021删除链表的倒数第n个节点.cpp` exists on disk but is not registered in the `.vcxproj` — likely a work-in-progress or duplicate of `19删除链表的倒数第n个节点_快慢指针.cpp`
- Encoding: files contain GBK/GB2312-encoded Chinese characters. Open with the correct encoding in editors outside VS.
- **README.md**: Must be kept in sync. When a new exercise is added or an existing one is completed, update `README.md` — add the entry to its category table, update the progress count, and add any new technique to the "常用技巧总结" section. The README is organized by data structure category (链表, 二叉树, etc.) with sub-groups by technique (快慢指针, 合并/运算, etc.).
