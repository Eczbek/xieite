# [xieite](../xieite.md)\:\:[containers](../containers.md)\:\:DynamicMatrix
Defined in header [<xieite/containers/DynamicMatrix.hpp>](../../include/xieite/containers/DynamicMatrix.hpp)

&nbsp;

## Description
A structure for generating dynamic multidimensional containers.

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
- [Type](./DynamicMatrix/1/Type.md)
#### 2)
```cpp
template<template<typename> typename DynamicContainer, typename Value>
struct DynamicMatrix<DynamicContainer, Value, 0> {
    using Type = Value;
};
```
##### Member types
- [Type](./DynamicMatrix/2/Type.md)

&nbsp;

## Example
```cpp
#include <iostream>
#include <vector>
#include <xieite/containers/DynamicMatrix.hpp>

int main() {
    std::cout
        << std::boolalpha
        << std::same_as<
            xieite::containers::DynamicMatrix<std::vector, int, 3>::Type,
            std::vector<std::vector<std::vector<int>>>
        > << '\n';
}
```
Output:
```
true
```
