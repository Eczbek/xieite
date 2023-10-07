# [xieite](../../xieite.md)\:\:[types](../../types.md)\:\:DynamicMatrix
Defined in header [<xieite/types/DynamicMatrix.hpp>](../../../include/xieite/types/DynamicMatrix.hpp)

&nbsp;

## Description
A structure for generating dynamic multidimensional types.

&nbsp;

## Synopses
#### 1)
```cpp
template<template<typename> typename DynamicContainer, typename Value, std::size_t dimensions>
struct DynamicMatrix {
    using Type = DynamicMatrix<DynamicContainer, DynamicContainer<Value>, dimensions - 1>::Type;
};
```
##### Member types
- [Type](./structures/DynamicMatrix/1/Type.md)
#### 2)
```cpp
template<template<typename> typename DynamicContainer, typename Value>
struct DynamicMatrix<DynamicContainer, Value, 0> {
    using Type = Value;
};
```
##### Member types
- [Type](./structures/DynamicMatrix/2/Type.md)

&nbsp;

## Example
```cpp
#include <iostream>
#include <vector>
#include <xieite/types/DynamicMatrix.hpp>

int main() {
    std::cout
        << std::boolalpha
        << std::same_as<
            xieite::types::DynamicMatrix<std::vector, int, 3>::Type,
            std::vector<std::vector<std::vector<int>>>
        > << '\n';
}
```
Output:
```
true
```
