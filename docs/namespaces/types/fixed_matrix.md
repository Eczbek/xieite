# [xieite](../../xieite.md)\:\:[types](../../types.md)\:\:FixedMatrix\<\>
Defined in fragment [xieite:types.FixedMatrix](../../../src/types/fixed_matrix.cpp)

&nbsp;

## Description
A type alias for generating multidimensional containers of fixed size.

&nbsp;

## Synopsis
#### 1)
```cpp
template<template<typename, std::size_t> typename FixedContainer, typename Value, std::size_t... sizes>
using FixedMatrix = /* ... */;
```

&nbsp;

## Example
```cpp
import std;
import xieite;

int main() {
    std::println("{}", std::same_as<
        xieite::types::FixedMatrix<std::array, int, 3, 2, 1>,
        std::array<std::array<std::array<int, 3>, 2>, 1>
    >);
}
```
Output:
```
true
```
