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
  *.cpp                     # 栈.cpp (基础演示, 未注册), 用栈实现链表头插法.cpp (未注册), 232用栈实现队列.cpp
  Queue/                    # Queue sub-project
    Queue.sln               # VS solution for queue
    Queue.vcxproj
    *.cpp                   # 队列.cpp (基础演示), deque双端队列.cpp (未注册), 225用队列实现栈.cpp
Array(vector)/              # Vector/array exercises (active)
  Array(vector).sln         # VS solution — open this
  Array(vector).vcxproj
  *.cpp                     # vector.cpp (基础演示), 118杨辉三角.cpp, 26删除数组中重复的元素.cpp, 383赎金信.cpp (数组版)
Set-Map/                    # Set/map associative containers (active)
  Set-Map.sln               # VS solution — open this
  Set-Map.vcxproj
  *.cpp                     # set.cpp (基础演示), map.cpp (基础演示), 1两数之和.cpp (map哈希法), 26删除有序数组的重复项.cpp (set对比版, 未注册)
String/                     # String exercises (active)
  String.sln                # VS solution — open this
  String.vcxproj
  *.cpp                     # string.cpp (基础演示)
HashTable/                  # Hash table exercises (active)
  HashTable.sln             # VS solution — open this
  HashTable.vcxproj
  *.cpp                     # 哈希表.cpp (基础演示), 13罗马数字转整数.cpp, 205同构字符串.cpp, 349两个数组的交集.cpp, 350两个数的交集2.cpp, 383赎金信.cpp
回放/                       # Screen recordings (.vep), not tracked in git
```

## Coding Conventions

**文件名带数字题号的就是力扣题**，遵循 LeetCode 风格；不带的（如头插法、尾插法）是基础操作演示，保留 C 风格即可。

### 力扣题（文件名含题号，如 `203移除链表元素.cpp`）

**VS 本地可编译运行。** 带 `#include` + `using namespace std`（VS 编码和编译检查需要），但不写 `main()`（避免多文件 `main` 冲突）。提交到 LeetCode 时手动去掉 `#include`、`using namespace std` 即可。

```cpp
#include <bits/stdc++.h>
using namespace std;

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

- 不写 `main()` — 多个 `.cpp` 各有 `main` 会导致链接冲突，当前项目依赖 VS 的"Excluded From Build"机制切换
- 中文注释可以保留
- 不释放 `dummyHead`（在 VS 本地测试时注意内存泄漏问题；LeetCode 会统一管理内存）

### 基础操作演示（文件名不含题号，如 `头插法_含new和malloc差异.cpp`）

- C 风格 `struct Node { int val; Node* next; }`，可带 `typedef`
- `createList()` / `printList()` / `freeList()` + `main()` 自驱动
- 保留教学注释（如 `new` vs `malloc` 的区别）
- 同样用 `new`/`delete`，不用 `malloc`/`free`

### 各项目特有说明

> **所有项目统一规则**：力扣题（文件名含题号数字）带 `#include <bits/stdc++.h>` + `using namespace std` + `struct ListNode`/`class Solution`，不写 `main()`。基础演示（不含题号）保留 `#include` + `using namespace std` + `main()` 自驱动。每个项目每次只编译一个 `.cpp`。

**Stack-Queue** — `Stack.sln` 管理栈相关 `.cpp`，`Queue/Queue.sln` 管理队列相关 `.cpp`。使用 STL 容器（`std::stack`、`std::queue`、`std::deque`）。文件名含"链表"/"头插法"说明是用栈/队列操作链表。

> ⚠️ Stack.vcxproj 只注册了 `232用栈实现队列.cpp`，缺少 `栈.cpp`、`用栈实现链表头插法.cpp`；Queue.vcxproj 缺少 `deque双端队列.cpp`。需补注册。

**Array(vector)** — 使用 `std::vector`。教学注释注明 API 用法（`push_back`/`insert`/`erase`/`at` vs `[]` 的区别等）。

**Set-Map** — `std::set`/`std::map`，底层红黑树。set：自动去重、默认升序、不支持随机访问（遍历用范围 for）。map：键值对存储（`pair<const Key, T>`），键唯一自动排序，`[]` 键不存在时会插入默认值，`find`/`count` 查找，`erase` 删除。力扣题如有 set/map 对比版本放此处（如 `26删除有序数组的重复项.cpp` 是双指针数组题 26 的 set 对比版），真正的算法版本放对应数据结构的项目。

**String** — 使用 `std::string`。

**HashTable** — `std::unordered_set`/`std::unordered_map`，底层哈希表。vs set/map：哈希表 O(1) 平均 vs 红黑树 O(log n)，无序 vs 自动排序；只关心快速查找/去重用 `unordered_set`，需要排序用 `set`。

### 共用规则

- 中文注释解释算法步骤
- 中文 `cout` 输出
- 虚头节点 (dummy head) 简化边界处理

## Notes

### 当前已知未注册文件

以下 `.cpp` 文件在磁盘上存在但 **未注册到 vcxproj**（无法在 VS 中编译，需手动添加 `<ClCompile Include="…" />`）：

| 文件 | 应注册到 |
|------|----------|
| `LinkedList/SingleList/203移除链表元素.cpp` | SingleList.vcxproj |
| `Stack-Queue/栈.cpp` | Stack.vcxproj |
| `Stack-Queue/用栈实现链表头插法.cpp` | Stack.vcxproj |
| `Stack-Queue/Queue/deque双端队列.cpp` | Queue/Queue.vcxproj |
| `Set-Map/26删除有序数组的重复项.cpp` | Set-Map.vcxproj |

### 检查未注册文件

对比磁盘上的 `.cpp` 和 vcxproj 中的 `<ClCompile Include>` 条目，差集即为未注册文件：

```bash
# 列出某项目目录下所有 .cpp（磁盘）
ls <ProjectDir>/*.cpp
# 列出 vcxproj 中已注册的 .cpp
grep -oP '(?<=Include=")[^"]+\.cpp' <ProjectDir>/<Project>.vcxproj
```

未注册的文件需手动编辑 vcxproj 添加 `<ClCompile Include="文件名.cpp" />`。

### 文件名 / 题号特殊情况

- `023相交链表.cpp` — 实际是 LeetCode **160**（相交链表），文件名用了 `023` 是历史原因，README 已正确标为 160。
- `021删除链表的倒数第n个节点.cpp` — 19 号的重复/变体，已在 vcxproj 中但可能是 WIP。
- `206反转链表.cpp` — 用头插法反转，README 归类为"反转链表"。
- `1两数之和.cpp` — LeetCode **1**（Two Sum），用 `std::map` 哈希法（O(n)），放在 Set-Map 项目中作为 map 应用演示。文件名不含"set/map"字样，README 应归于 Set-Map 分类。

### 力扣题规范违规检查

力扣题文件（文件名含题号数字）不写 `main()`（避免多文件链接冲突）。用以下命令检查：

```bash
# 找出所有力扣题文件中含有 main() 的
grep -l 'main()' -- *[0-9]*.cpp
```

> 基础演示文件（如 `栈.cpp`、`vector.cpp`、`set.cpp` 等不含题号的文件）按规范需要 `main()`，不在违规之列。

### Git / README 工作流

每次 `git commit` + `git push` 之前，必须检查并同步更新 `README.md`：
- 新增的力扣题加入对应分类表格，更新进度统计数字
- 新出现的技巧加入"常用技巧总结"
- 基础演示文件或新项目目录有变化也要反映到 README
- 参见 `.claude/memory/README-sync.md`

### 编码

文件含 GBK/GB2312 编码的中文字符。在 VS 之外的编辑器打开时需选择正确编码。
