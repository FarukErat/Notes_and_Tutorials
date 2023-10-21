
# BBTree Readme

The `BBTree` is a C++ template class that implements basic operations for adding, removing, and finding elements as efficiently as Balanced Binary Tree with less complexity. This README provides an overview of the `BBTree` class and how to use it.

## Table of Contents
- [Introduction](#introduction)
- [Features](#features)
- [Usage](#usage)
- [Example](#example)
- [Contributing](#contributing)

## Introduction

The `BBTree` is a header-only C++ template class that implements a binary search tree (BST) for maintaining a sorted list of elements. The tree maintains the elements in sorted order, allowing for efficient search and insertion. The class provides the following methods:

- `void print()`: Print the elements in the tree in sorted order.
- `void add(T value, bool unique = false)`: Add an element to the tree. The `unique` parameter allows you to control whether duplicate values are allowed.
- `void remove(T value)`: Remove an element from the tree.
- `bool find(T value)`: Check if a value exists in the tree.

## Features

- **Binary Search Tree**: The `BBTree` is implemented as a binary search tree, ensuring efficient searching and insertion operations.
- **Sorted Order**: The elements in the tree are always maintained in sorted order, making it easy to retrieve them in ascending order.
- **Unique Values**: You can choose whether to allow duplicate values when adding elements to the tree by setting the `unique` parameter in the `add` method.
- **Header-Only**: The `BBTree` is a header-only class, making it easy to include in your C++ projects without the need for separate compilation.

## Usage

To use the `BBTree` class in your C++ project, follow these steps:

1. Copy the provided `BBTree` code into a header file (e.g., `BBTree.h`) in your project.

2. Include the header in your C++ source code where you want to use the `BBTree` class:

   ```cpp
   #include "BBTree.h"
   ```

3. Instantiate a `BBTree` object with the desired element type. For example:

   ```cpp
   BBTree<int> tree;
   ```

4. You can now use the `BBTree` object to perform operations like adding, removing, and finding elements in sorted order.

## Example

Here's a simple example of using the `BBTree` class:

```cpp
#include "BBTree.h"
#include <iostream>

int main() {
    BBTree<int> tree;

    tree.add(5);
    tree.add(3);
    tree.add(7);
    tree.add(1);
    tree.add(3);  // Adding a duplicate value (allowed by default)

    tree.print(); // Print elements in sorted order: 1 3 3 5 7

    tree.remove(3);
    tree.print(); // After removing one occurrence of 3: 1 3 5 7

    bool found = tree.find(5);
    if (found) {
        std::cout << "Value 5 found in the tree." << std::endl;
    } else {
        std::cout << "Value 5 not found in the tree." << std::endl;
    }

    return 0;
}
```

## Contributing

Contributions to the `BBTree` class are welcome. If you'd like to contribute, please follow the guidelines outlined in the [CONTRIBUTING.md](CONTRIBUTING.md) file.


---

**Note**: This README serves as a basic introduction to the `BBTree` class. Be sure to consult the actual header file for more details and any specific usage instructions.
