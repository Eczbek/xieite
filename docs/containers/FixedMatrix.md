# [xieite](../xieite.md)\:\:[containers](../containers.md)\:\:FixedMatrix
Defined in header [<xieite/containers/FixedMatrix.hpp>](../../include/xieite/containers/FixedMatrix.hpp)

&nbsp;

## Description
A structure for generating multidimensional containers of fixed size.

&nbsp;

## Synopses
#### 1)
```cpp
template<template<typename, std::size_t> typename, typename, std::size_t...>
struct FixedMatrix;
```
#### 2)
```cpp
template<template<typename, std::size_t> typename FixedContainer, typename Value, std::size_t sizesFirst, std::size_t... sizesRest>
struct FixedMatrix<FixedContainer, Value, sizesFirst, sizesRest...> {
    using Type = FixedMatrix<FixedContainer, FixedContainer<Value, sizesFirst>, sizesRest...>::Type;
};
```
##### Member types
- [Type](./FixedMatrix/2/Type.md)
#### 3)
```cpp
template<template<typename, std::size_t> typename FixedContainer, typename Value, std::size_t size>
struct FixedMatrix<FixedContainer, Value, size> {
    using Type = FixedContainer<Value, size>;
};
```
##### Member types
- [Type](./FixedMatrix/3/Type.md)
#### 4)
```cpp
template<template<typename, std::size_t> typename FixedContainer, typename Value>
struct FixedMatrix<FixedContainer, Value> {
    using Type = Value;
};
```
##### Member types
- [Type](./FixedMatrix/4/Type.md)

&nbsp;

## Example
```cpp
#include <array>
#include <iostream>
#include <xieite/containers/DynamicMatrix.hpp>

int main() {
    std::cout
        << std::boolalpha
        << std::same_as<
            xieite::containers::FixedMatrix<std::array, int, 3, 2, 1>::Type,
            std::array<std::array<std::array<int, 3>, 2>, 1>
        > << '\n';
}
```
Output:
```
true
```
