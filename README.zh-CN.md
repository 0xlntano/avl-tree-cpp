# C++ AVL Tree

[中文](./README.zh-CN.md) | [English](./README.en.md)

一个手写的 C++ AVL 树实现项目，用来学习和练习自平衡二叉搜索树的核心原理。

## 项目简介

这个项目从零实现了一棵 AVL 树，并在基础的插入、删除、查找之外，进一步加入了类似 `__gnu_pbds::tree` 的顺序统计功能。

## 当前功能

- AVL 树节点与类封装
- 高度维护与平衡因子计算
- 左旋与右旋
- 插入 `insert(int key)`
- 删除 `erase(int key)`
- 查找 `contains(int key)`
- 先序遍历 `preorder()`
- 中序遍历 `inorder()`
- 子树大小维护 `size()`
- 顺序统计 `order_of_key(int key)`
- 第 k 小查询 `find_by_order(int k, int& result)`

## 文件说明

- `avl.cpp`：完整的 `AVLTree` 实现，以及 `main()` 中的简单测试

## 编译

使用 `g++` 编译：

```bash
g++ avl.cpp -std=c++17 -O2 -o avl.exe
```

## 运行

在 Windows 下可以直接运行：

```bash
avl.exe
```

在类 Unix 环境下可以运行：

```bash
./avl.exe
```

## 已实现接口

当前 `AVLTree` 类提供以下接口：

- `insert(int key)`
- `erase(int key)`
- `contains(int key)`
- `size()`
- `order_of_key(int key)`
- `find_by_order(int k, int& result)`
- `preorder()`
- `inorder()`

## 接口说明

- `contains(x)`
  判断值 `x` 是否存在于树中。

- `order_of_key(x)`
  返回严格小于 `x` 的元素个数。

- `find_by_order(k, result)`
  查询第 `k` 小的元素，`k` 从 `0` 开始；若存在则返回 `true` 并把结果写入 `result`。

## 当前限制

- 当前实现是 `set` 风格，不支持重复值
- 为了便于学习，代码目前仍放在单个源文件中
- `main()` 里包含的是演示性质的测试，而不是完整单元测试

## 后续可扩展方向

- 拆分为头文件和源文件
- 支持重复值，扩展成接近 `multiset` 的版本
- 提供更接近 PBDS 的接口形式
- 增加层序遍历和更系统的测试
