# [xieite](../../xieite.md)\:\:[types](../../types.md)\:\:DynamicMatrix
Defined in header [<xieite/types/dynamic_matrix.hpp>](../../../include/xieite/types/dynamic_matrix.hpp)

&nbsp;

## Description
A type alias for generating dynamic multidimensional containers.

&nbsp;

## Synopsis
#### 1)
```cpp
template<template<typename> typename DynamicContainer_, typename Value_, std::size_t dimensions_>
using DynamicMatrix = /* ... */;
```

&nbsp;

## Example
```cpp
#include <print>
#include <vector>
#include "xieite/types/dynamic_matrix.hpp"

int main() {
    std::println("{}", std::same_as<
        xieite::types::DynamicMatrix<std::vector, int, 3>::Type,
        std::vector<std::vector<std::vector<int>>>
    >);
}
```
Output:
```
true
```
