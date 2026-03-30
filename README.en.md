# AVL Tree in C++

[中文](./README.zh-CN.md) | [English](./README.en.md)

A hand-written AVL tree implementation in C++ for learning and practicing the core ideas behind self-balancing binary search trees.

## Overview

This project implements an AVL tree from scratch and extends the basic insert, erase, and search operations with order-statistics features similar to `__gnu_pbds::tree`.

## Features

- AVL tree node structure and class-based encapsulation
- Height maintenance and balance-factor calculation
- Left and right rotations
- Insertion with `insert(int key)`
- Deletion with `erase(int key)`
- Search with `contains(int key)`
- Preorder traversal with `preorder()`
- Inorder traversal with `inorder()`
- Subtree-size maintenance with `size()`
- Order statistics with `order_of_key(int key)`
- K-th element query with `find_by_order(int k, int& result)`

## Files

- `avl.cpp`: full `AVLTree` implementation and a simple test in `main()`

## Build

Compile with `g++`:

```bash
g++ avl.cpp -std=c++17 -O2 -o avl.exe
```

## Run

On Windows:

```bash
avl.exe
```

On Unix-like systems:

```bash
./avl.exe
```

## Public API

The current `AVLTree` class provides:

- `insert(int key)`
- `erase(int key)`
- `contains(int key)`
- `size()`
- `order_of_key(int key)`
- `find_by_order(int k, int& result)`
- `preorder()`
- `inorder()`

## API Notes

- `contains(x)`
  Checks whether `x` exists in the tree.

- `order_of_key(x)`
  Returns the number of elements strictly smaller than `x`.

- `find_by_order(k, result)`
  Finds the k-th smallest element using zero-based indexing; returns `true` and writes the answer into `result` if it exists.

## Current Limitations

- The current implementation behaves like a `set` and does not support duplicate keys
- For simplicity and learning purposes, the code is currently kept in a single source file
- The tests in `main()` are demonstrations rather than a full unit-test suite

## Future Improvements

- Split the project into header and source files
- Support duplicate keys and extend it toward a `multiset`-style implementation
- Provide an interface closer to PBDS
- Add level-order traversal and more systematic tests
