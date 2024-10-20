# [xieite](../../xieite.md)\:\:[types](../../types.md)\:\:DynamicMatrix\<\>
Defined in fragment [xieite:types.DynamicMatrix](../../../src/types/dynamic_matrix.cpp)

&nbsp;

## Description
A type alias for generating dynamic multidimensional containers.

&nbsp;

## Synopsis
#### 1)
```cpp
template<template<typename> typename DynamicContainer, typename Value, std::size_t dimensions>
using DynamicMatrix = /* ... */;
```

&nbsp;

## Example
```cpp
import std;
import xieite;

int main() {
    std::println("{}", std::same_as<
        xieite::types::DynamicMatrix<std::vector, int, 3>,
        std::vector<std::vector<std::vector<int>>>
    >);
}
```
Output:
```
true
```
