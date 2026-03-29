# AVL Tree in C++

A hand-written AVL tree implementation in C++. This project is mainly for learning and practicing how a self-balancing binary search tree works.

## Features

- AVL tree node structure
- Height maintenance
- Left rotation and right rotation
- Insertion
- Deletion
- Search with `contains()`
- Preorder traversal
- Inorder traversal

## File

- `avl.cpp`: complete AVL tree implementation and a simple test in `main()`

## Build

Use `g++` to compile:

```bash
g++ avl.cpp -std=c++17 -O2 -o avl.exe
```

## Run

```bash
./avl.exe
```

On Windows Command Prompt, you can also run:

```bash
avl.exe
```

## What Is Implemented

The current code is wrapped in an `AVLTree` class and supports these public operations:

- `insert(int key)`
- `erase(int key)`
- `contains(int key)`
- `preorder()`
- `inorder()`

## Notes

- Duplicate keys are ignored.
- The project currently uses a single source file for simplicity.
- `main()` contains sample insertion, deletion, and search tests.

## Future Improvements

- Split code into header and source files
- Add level-order traversal
- Support order statistics like `find_by_order` and `order_of_key`
- Add better test cases
