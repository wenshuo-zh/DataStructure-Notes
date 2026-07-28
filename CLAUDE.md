# CLAUDE.md

This file provides guidance to Claude Code (claude.ai/code) when working with code in this repository.

## Overview

Personal C++ data structures practice repository. Content is in Chinese (comments, variable names, output messages). Currently focused on linked lists, with plans to expand to other data structures.

## Build System

- **Environment**: Visual Studio 2022, Windows 11, v143 toolset
- **Solution**: Open `LinkedList/SingleList/SingleList.sln` in VS 2022
- **Build**: Debug x64 (default). Each `.cpp` in the project is a self-contained exercise with its own `main()` — only one should be compiled at a time. Exclude the others from build before compiling.
- **Output**: `x64/Debug/SingleList.exe`

## Repository Structure

```
.gitignore                  # VS/C++ build artifacts, .vs/, x64/, *.ipch, etc.
01 26.7.26/                 # Deprecated — being migrated to LinkedList/
02 26.7.28/                 # Deprecated — being migrated to LinkedList/
LinkedList/SingleList/      # Active project — single linked list exercises
回放/                       # Screen recordings (.vep), not tracked in git
```

## Coding Conventions

### Old exercises (deprecated, in `01`/`02` directories)
- C-style `struct Node { int val; Node* next; }` with `typedef`
- Pattern: `createList(n)` → `printList(head)` → `freeList(head)`
- Uses dummy head node + tail pointer for tail insert; dummy head for head insert
- Allocates with `new`, deallocates with `delete`

### Current exercises (in `LinkedList/SingleList/`)
- LeetCode-style `struct ListNode` with constructors:
  ```cpp
  struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };
  ```
- Logic encapsulated in a `class Solution` with public methods
- I/O is separate from the algorithm (LeetCode pattern: function takes input, returns result)

### Shared conventions
- `#include<iostream>` and `using namespace std;` at the top of every file
- Chinese comments (`// 快指针先走n步`) and Chinese `cout` messages
- `new`/`delete` for heap allocation (not `malloc`/`free`)

## Migration In Progress

The repo is transitioning from flat dated folders (`01 26.7.26/`, `02 26.7.28/`) to a structure organized by data structure type (`LinkedList/SingleList/`). Old `.cpp` files are being rewritten into the new project. When adding new exercises, place them in the appropriate data structure subdirectory within `LinkedList/SingleList/`.
