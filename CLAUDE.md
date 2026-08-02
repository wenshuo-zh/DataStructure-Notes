# CLAUDE.md

This file provides guidance to Claude Code (claude.ai/code) when working with code in this repository.

## Overview

Personal C++ data structures practice repo. Content is in Chinese (comments, variable names, `cout` messages). Active projects: singly linked lists (SingleList), stack & queue (Stack-Queue), vector/array (Array(vector)), set/map (Set-Map), string (String), hash table (HashTable). DoublyLinkedList is scaffolded but empty.

Remote: `https://github.com/wenshuo-zh/DataStructure-Notes.git`

## 语言

全程使用中文与用户交流（代码和技术术语除外）。

## Build System

- **Environment**: Visual Studio 2022, Windows 11, v143 toolset (C++17+)
- **Solutions**: One VS solution per data structure:
  - `LinkedList/SingleList/SingleList.sln` — singly linked list exercises
  - `LinkedList/DoublyLinkedList/DoublyLinkedList.sln` — doubly linked list (no exercises yet)
  - `Stack-Queue/Stack.sln` — stack exercises
  - `Stack-Queue/Queue/Queue.sln` — queue exercises
  - `Array(vector)/Array(vector).sln` — vector/array exercises (LeetCode 118 杨辉三角, 26 去重)
  - `Set-Map/Set-Map.sln` — set/map associative containers
  - `String/String.sln` — string exercises
  - `HashTable/HashTable.sln` — hash table / unordered_set exercises
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

# Set-Map (Set-Map\):
msbuild Set-Map.sln /p:Configuration=Debug /p:Platform=x64

# String (String\):
msbuild String.sln /p:Configuration=Debug /p:Platform=x64

# HashTable (HashTable\):
msbuild HashTable.sln /p:Configuration=Debug /p:Platform=x64
```

Or from repo root with full paths:

```cmd
msbuild LinkedList\SingleList\SingleList.sln /p:Configuration=Debug /p:Platform=x64
```

### Adding a new .cpp file (outside VS)

When adding a `.cpp` file without Visual Studio, you must manually edit the `.vcxproj` file — add a `<ClCompile Include="新文件.cpp" />` entry inside the existing `<ItemGroup>` that contains the other `<ClCompile>` entries. VS would do this automatically via "Add → Existing Item", but CLI users must edit the XML directly.

### Adding a new project (e.g., a new data structure)

**Must be done inside Visual Studio** — do NOT attempt to manually create `.sln` / `.vcxproj` / `.vcxproj.filters` files. VS generates GUIDs and XML structure that hand-authoring gets wrong. Steps:
1. VS → 文件 → 新建 → 项目 → 控制台应用 (C++, Windows, v143)
2. Name and place it in the proper subdirectory
3. Then add existing `.cpp` files or create new ones
4. After creation, update this CLAUDE.md and README.md to reflect the new project

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
  *.cpp                     # vector.cpp (基础演示), 118杨辉三角.cpp, 26删除数组中重复的元素.cpp, 383赎金信.cpp (数组版)
Set-Map/                    # Set/map associative containers (active)
  Set-Map.sln               # VS solution — open this
  Set-Map.vcxproj
  *.cpp                     # set.cpp (基础演示), map.cpp (基础演示), 1两数之和.cpp (map哈希法), 26删除有序数组的重复项.cpp (set对比版)
String/                     # String exercises (active)
  String.sln                # VS solution — open this
  String.vcxproj
  *.cpp                     # string.cpp (基础演示)
HashTable/                  # Hash table exercises (active)
  HashTable.sln             # VS solution — open this
  HashTable.vcxproj
  *.cpp                     # 哈希表.cpp (基础演示占位), 349两个数组的交集.cpp, 350两个数的交集2.cpp, 383赎金信.cpp
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

### Set-Map 项目（`Set-Map/` 目录）

- 使用 STL 关联式容器（`std::set`、`std::map`），底层红黑树
- 基础演示保留 `#include` + `using namespace std` + `main()`
- set 特性：自动去重、默认升序、不支持随机访问（遍历用范围 for 而非下标）
- map 特性：键值对存储（`pair<const Key, T>`）、键唯一自动排序、支持 `[]`/`at` 访问（`[]` 键不存在时会插入默认值）、`find`/`count` 查找、`erase` 删除
- 力扣题如有 set/map 对比版本放此处，真正的算法版本放对应数据结构的项目
- 力扣题（如 `1两数之和.cpp`）同样应按力扣规范（只有 `class Solution`），但目前部分文件仍有 `#include<bits/stdc++.h>`，见 Notes 中的违规列表

### String 项目（`String/` 目录）

- 使用 STL `std::string`，基础演示保留 `#include` + `using namespace std` + `main()`
- 力扣题按力扣规范：只有 `class Solution`，不放 `#include`/`main()`
- 同样遵守"每次只编译一个 `.cpp`"规则

### HashTable 项目（`HashTable/` 目录）

- 使用 STL 无序容器（`std::unordered_set`、`std::unordered_map`），底层哈希表
- 基础演示保留 `#include` + `using namespace std` + `main()`
- `unordered_set` vs `set`：哈希表 O(1) 平均查找 vs 红黑树 O(log n)，无序 vs 自动排序；需要排序或有序遍历时用 `set`，只关心快速查找/去重时用 `unordered_set`
- 力扣题同样按力扣规范（只有 `class Solution`），目前 `349两个数组的交集.cpp` 仍有 `#include<bits/stdc++.h>`

### 共用规则

- 中文注释解释算法步骤
- 中文 `cout` 输出
- 虚头节点 (dummy head) 简化边界处理

## Notes

### 构建 / 文件注册

- 每个 `.cpp` 文件都有独立的 `main()`，**同一时间只能编译一个 `.cpp`**。在 VS 中：右键不需要的 `.cpp` → Properties → "Excluded From Build" → Yes。
- 添加新 `.cpp` 时需手动编辑 `.vcxproj`，在 `<ItemGroup>` 中添加 `<ClCompile Include="新文件.cpp" />`。
- 以下文件**在磁盘上存在但未注册到 vcxproj**，如需编译需先注册：
  | 项目 | 未注册的文件 |
  |------|-------------|
  | SingleList | `203移除链表元素.cpp` |
  | Stack | `栈.cpp`、`用栈实现链表头插法.cpp` |
  | Queue | `deque双端队列.cpp` |
  | Array(vector) | 无（`vector.cpp` 已注册） |
  | Set-Map | `set.cpp`、`26删除有序数组的重复项.cpp` |
  | HashTable | `349两个数组的交集.cpp`、`350两个数的交集2.cpp`、`383赎金信.cpp`、`哈希表.cpp` |

### 文件名 / 题号特殊情况

- `023相交链表.cpp` — 实际是 LeetCode **160**（相交链表），文件名用了 `023` 是历史原因，README 已正确标为 160。
- `021删除链表的倒数第n个节点.cpp` — 19 号的重复/变体，已在 vcxproj 中但可能是 WIP。
- `206反转链表.cpp` — 用头插法反转，README 归类为"反转链表"。
- `1两数之和.cpp` — LeetCode **1**（Two Sum），用 `std::map` 哈希法（O(n)），放在 Set-Map 项目中作为 map 应用演示。文件名不含"set/map"字样，README 应归于 Set-Map 分类。

### 力扣题规范违规

以下力扣题文件含有 `#include<bits/stdc++.h>`，应移除以符合规范（只保留 `struct ListNode` + `class Solution`）：

- `141环形链表.cpp`
- `023相交链表.cpp`
- `118杨辉三角.cpp`
- `26删除数组中重复的元素.cpp`（Array(vector) 项目中的双指针版本）
- `232用栈实现队列.cpp`
- `225用队列实现栈.cpp`
- `26删除有序数组的重复项.cpp`（Set-Map 项目中的 set 对比版）
- `1两数之和.cpp`
- `349两个数组的交集.cpp`（HashTable 项目，unordered_set 解法）
- `350两个数的交集2.cpp`（HashTable 项目，unordered_map 计数解法）
- `383赎金信.cpp`（HashTable 项目，unordered_map 哈希版）
- `383赎金信.cpp`（Array(vector) 项目，int[26] 数组版）

> 基础演示文件（如 `栈.cpp`、`vector.cpp`、`set.cpp` 等）按规范可以保留 `#include` + `main()`，不在违规之列。

### Git / README 工作流

每次 `git commit` + `git push` 之前，必须检查并同步更新 `README.md`：
- 新增的力扣题加入对应分类表格，更新进度统计数字
- 新出现的技巧加入"常用技巧总结"
- 基础演示文件或新项目目录有变化也要反映到 README
- 参见 `.claude/memory/README-sync.md`

### 编码

文件含 GBK/GB2312 编码的中文字符。在 VS 之外的编辑器打开时需选择正确编码。
