---
name: readme-sync
description: 提交代码时必须同步更新 README.md 的刷题进度
metadata:
  type: project
---

每次 `git commit` + `git push` 之前，必须检查并更新 `README.md`：
- 新增的力扣题加入对应分类表格，更新进度统计数字
- 完成的题目去掉 🚧 标记
- 新出现的技巧加入"常用技巧总结"
- 不止力扣题，基础演示文件或新项目目录有变化也要反映到 README

**Why:** 用户用 README 在 GitHub 上展示刷题进度，README 落后于实际代码会让记录失去价值。

**How to apply:** 每次 push 前，先扫描所有项目目录下 `.cpp` 文件，对照 README 的题目列表，有差异就更新。
