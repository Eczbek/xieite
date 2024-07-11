# [xieite](../../xieite.md)\:\:[types](../../types.md)\:\:FixedMatrix\<\>
Defined in header [<xieite/types/fixed_matrix.hpp>](../../../include/xieite/types/fixed_matrix.hpp)

&nbsp;

## Description
A type alias for generating multidimensional containers of fixed size.

&nbsp;

## Synopsis
#### 1)
```cpp
template<template<typename, std::size_t> typename FixedContainer_, typename Value_, std::size_t... sizes_>
using FixedMatrix = /* ... */;
```

&nbsp;

## Example
```cpp
#include <array>
#include <print>
#include "xieite/types/dynamic_matrix.hpp"

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
