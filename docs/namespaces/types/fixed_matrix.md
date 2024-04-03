# [xieite](../../xieite.md)\:\:[types](../../types.md)\:\:FixedMatrix \{\}
Defined in header [<xieite/types/fixed_matrix.hpp>](../../../include/xieite/types/fixed_matrix.hpp)

&nbsp;

## Description
A structure for generating multidimensional containers of fixed size.

&nbsp;

## Synopsis
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
##### Members
- Type
#### 3)
```cpp
template<template<typename, std::size_t> typename FixedContainer, typename Value, std::size_t size>
struct FixedMatrix<FixedContainer, Value, size> {
    using Type = FixedContainer<Value, size>;
};
```
##### Members
- Type
#### 4)
```cpp
template<template<typename, std::size_t> typename FixedContainer, typename Value>
struct FixedMatrix<FixedContainer, Value> {
    using Type = Value;
};
```
##### Members
- Type

&nbsp;

## Example
```cpp
#include <array>
#include <print>
#include "xieite/types/dynamic_matrix.hpp"

int main() {
    std::println("{}", std::same_as<
        xieite::types::FixedMatrix<std::array, int, 3, 2, 1>::Type,
        std::array<std::array<std::array<int, 3>, 2>, 1>
    >);
}
```
Output:
```
true
```
