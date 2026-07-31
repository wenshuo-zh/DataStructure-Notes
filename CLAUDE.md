# CLAUDE.md

This file provides guidance to Claude Code (claude.ai/code) when working with code in this repository.

## Overview

Personal C++ data structures practice repo. Content is in Chinese (comments, variable names, `cout` messages). Active projects: singly linked lists (SingleList), stack & queue (Stack-Queue), vector/array (Array(vector)). DoublyLinkedList is scaffolded but empty.

Remote: `https://github.com/wenshuo-zh/DataStructure-Notes.git`

## Build System

- **Environment**: Visual Studio 2022, Windows 11, v143 toolset (C++17+)
- **Solutions**: One VS solution per data structure:
  - `LinkedList/SingleList/SingleList.sln` — singly linked list exercises
  - `LinkedList/DoublyLinkedList/DoublyLinkedList.sln` — doubly linked list (no exercises yet)
  - `Stack-Queue/Stack.sln` — stack exercises
  - `Stack-Queue/Queue/Queue.sln` — queue exercises
  - `Array(vector)/Array(vector).sln` — vector/array exercises (LeetCode 118 杨辉三角)
- **Configuration**: Debug x64 (default); Release x64 also available
- **Critical**: Every `.cpp` file in a project defines its own `main()`. **Only one `.cpp` file can be compiled at a time.** To switch exercises in VS: right-click the unwanted `.cpp` files → Properties → "Excluded From Build" → Yes. Keep only the one you want active.
- **Build output**: `<ProjectDir>/x64/Debug/<ProjectName>.exe`

### Building from CLI (MSBuild)

Each project has its own `.sln` in a different subdirectory. Run from the project directory:

```cmd
# SingleList (LinkedList\SingleList\):
msbuild SingleList.sln /p:Configuration=Debug /p:Platform=x64

# DoublyLinkedList (LinkedList\DoublyLinkedList\):
msbuild DoublyLinkedList.sln /p:Configuration=Debug /p:Platform=x64

# Stack (Stack-Queue\):
msbuild Stack.sln /p:Configuration=Debug /p:Platform=x64

# Queue (Stack-Queue\Queue\):
msbuild Queue.sln /p:Configuration=Debug /p:Platform=x64

# Array(vector) (Array(vector)\):
msbuild "Array(vector).sln" /p:Configuration=Debug /p:Platform=x64
```

Or from repo root with full paths:

```cmd
msbuild LinkedList\SingleList\SingleList.sln /p:Configuration=Debug /p:Platform=x64
```

### Adding a new .cpp file (outside VS)

When adding a `.cpp` file without Visual Studio, you must manually edit the `.vcxproj` file — add a `<ClCompile Include="新文件.cpp" />` entry inside the existing `<ItemGroup>` that contains the other `<ClCompile>` entries. VS would do this automatically via "Add → Existing Item", but CLI users must edit the XML directly.

## Repository Structure

```
.gitignore                  # VS/C++ build artifacts, .vs/, x64/, *.ipch, etc.
LinkedList/SingleList/      # Singly linked list exercises (active)
  SingleList.sln            # VS solution — open this
  SingleList.vcxproj        # MSBuild project (v143, console app, Debug/Release x64+Win32)
  *.cpp                     # Self-contained exercises (one per LeetCode problem)
LinkedList/DoublyLinkedList/ # Doubly linked list (scaffold only — no .cpp files yet)
  DoublyLinkedList.sln
  DoublyLinkedList.vcxproj
Stack-Queue/                # Stack & queue exercises (active)
  Stack.sln                 # VS solution for stack
  Stack.vcxproj
  *.cpp                     # Stack exercises (栈.cpp, 用栈实现链表头插法.cpp)
  Queue/                    # Queue sub-project
    Queue.sln               # VS solution for queue
    Queue.vcxproj
    *.cpp                   # Queue exercises (队列.cpp, deque双端队列.cpp)
Array(vector)/              # Vector/array exercises (active)
  Array(vector).sln         # VS solution — open this
  Array(vector).vcxproj
  *.cpp                     # vector.cpp (基础演示), 118杨辉三角.cpp (WIP)
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

### Stack-Queue 项目（`Stack-Queue/` 目录）

- `Stack.sln` 管理栈相关 `.cpp`，`Queue/Queue.sln` 管理队列相关 `.cpp`
- 基础演示保留 `#include` + `using namespace std`（如 `栈.cpp`、`队列.cpp`）
- 使用 STL 容器（`std::stack`、`std::queue`、`std::deque`）或自建结构
- 文件名如含"链表"或"头插法"字样说明是用栈/队列操作链表
- 同样遵守"每次只编译一个 `.cpp`"规则

### Array(vector) 项目（`Array(vector)/` 目录）

- 使用 STL `std::vector`，基础演示保留 `#include` + `using namespace std` + `main()`
- 力扣题（如 `118杨辉三角.cpp`）同样按力扣规范：只有 `class Solution`，不放 `#include`/`main()`
- 教学注释注明 API 用法（如 `push_back`、`insert`、`erase`、`at` vs `[]` 的区别等）

### 共用规则

- 中文注释解释算法步骤
- 中文 `cout` 输出
- 虚头节点 (dummy head) 简化边界处理

## Notes

- The `.vcxproj` file lists registered `.cpp` files. When adding a new exercise:
  1. Add the `.cpp` to the appropriate project directory
  2. In VS: right-click Source Files → Add → Existing Item, or manually edit the `.vcxproj` `<ClCompile>` list
  3. Exclude all other `.cpp` files from build so only the new one compiles
- `021删除链表的倒数第n个节点.cpp` — duplicate of `19` (same problem, different approach). Registered in `.vcxproj` but likely a WIP variant
- `203移除链表元素.cpp` exists on disk in `SingleList/` but is **not registered** in the `.vcxproj` — needs to be added if you want to compile it
- `023相交链表.cpp` — this is actually LeetCode **160** (相交链表). The filename uses `023` instead of `160` for historical reasons; the README correctly lists it as 160
- `206反转链表.cpp` — uses 头插法 to reverse; categorized as "反转链表" in README
- `118杨辉三角.cpp` — two implementations (push_back and resize); has `#include<bits/stdc++.h>` (力扣题 convention violation, same as 141)
- `141环形链表.cpp` has `#include<bits/stdc++.h>` (convention violation — should be removed per 力扣题 rules)
- `225用队列实现栈.cpp` — in Queue project, dual-queue approach (push O(n), pop O(1))
- `232用栈实现队列.cpp` — in Stack project, dual-stack `inStack`/`outStack` approach (均摊 O(1))
- Encoding: files contain GBK/GB2312-encoded Chinese characters. Open with the correct encoding in editors outside VS.
- **README.md**: Must be kept in sync. When a new exercise is added or an existing one is completed, update `README.md` — add the entry to its category table, update the progress count, and add any new technique to the "常用技巧总结" section. The README is organized by data structure category (链表, 二叉树, etc.) with sub-groups by technique (快慢指针, 合并/运算, etc.).
