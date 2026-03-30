# AVL Tree in C++ / C++ AVL Tree

一个手写的 C++ AVL 树实现项目，用来学习和练习自平衡二叉搜索树的核心原理。  
A hand-written AVL tree implementation in C++ for learning and practicing the core ideas behind self-balancing binary search trees.

## 项目简介 / Overview

这个项目从零实现了一棵 AVL 树，并在基础的插入、删除、查找之外，进一步加入了类似 `__gnu_pbds::tree` 的顺序统计功能。  
This project implements an AVL tree from scratch and extends the basic insert, erase, and search operations with order-statistics features similar to `__gnu_pbds::tree`.

## 当前功能 / Features

- AVL 树节点与类封装  
  AVL tree node structure and class-based encapsulation
- 高度维护与平衡因子计算  
  Height maintenance and balance-factor calculation
- 左旋与右旋  
  Left and right rotations
- 插入 `insert(int key)`  
  Insertion with `insert(int key)`
- 删除 `erase(int key)`  
  Deletion with `erase(int key)`
- 查找 `contains(int key)`  
  Search with `contains(int key)`
- 先序遍历 `preorder()`  
  Preorder traversal with `preorder()`
- 中序遍历 `inorder()`  
  Inorder traversal with `inorder()`
- 子树大小维护 `size()`  
  Subtree-size maintenance with `size()`
- 顺序统计 `order_of_key(int key)`  
  Order statistics with `order_of_key(int key)`
- 第 k 小查询 `find_by_order(int k, int& result)`  
  K-th element query with `find_by_order(int k, int& result)`

## 文件说明 / Files

- `avl.cpp`  
  完整的 AVLTree 实现，以及 `main()` 中的简单测试。  
  Full `AVLTree` implementation and a simple test in `main()`.

## 编译 / Build

使用 `g++` 编译：  
Compile with `g++`:

```bash
g++ avl.cpp -std=c++17 -O2 -o avl.exe
```

## 运行 / Run

在 Windows 下可以直接运行：  
On Windows, you can run:

```bash
avl.exe
```

在类 Unix 环境下可以运行：  
On Unix-like systems, you can run:

```bash
./avl.exe
```

## 已实现接口 / Public API

当前 `AVLTree` 类提供以下接口：  
The current `AVLTree` class provides the following public interfaces:

- `insert(int key)`
- `erase(int key)`
- `contains(int key)`
- `size()`
- `order_of_key(int key)`
- `find_by_order(int k, int& result)`
- `preorder()`
- `inorder()`

## 接口说明 / API Notes

- `contains(x)`  
  判断值 `x` 是否存在于树中。  
  Checks whether `x` exists in the tree.

- `order_of_key(x)`  
  返回严格小于 `x` 的元素个数。  
  Returns the number of elements strictly smaller than `x`.

- `find_by_order(k, result)`  
  查询第 `k` 小的元素，`k` 从 `0` 开始；若存在则返回 `true` 并把结果写入 `result`。  
  Finds the k-th smallest element using zero-based indexing; returns `true` and writes the answer into `result` if it exists.

## 当前限制 / Current Limitations

- 当前实现是 `set` 风格，不支持重复值。  
  The current implementation behaves like a `set` and does not support duplicate keys.
- 为了便于学习，代码目前仍放在单个源文件中。  
  For simplicity and learning purposes, the code is currently kept in a single source file.
- `main()` 里包含的是演示性质的测试，而不是完整单元测试。  
  The tests in `main()` are demonstrations rather than a full unit-test suite.

## 后续可扩展方向 / Future Improvements

- 拆分为头文件和源文件  
  Split the project into header and source files
- 支持重复值，扩展成接近 `multiset` 的版本  
  Support duplicate keys and extend it toward a `multiset`-style implementation
- 提供更接近 PBDS 的接口形式  
  Provide an interface closer to PBDS
- 增加层序遍历和更系统的测试  
  Add level-order traversal and more systematic tests
