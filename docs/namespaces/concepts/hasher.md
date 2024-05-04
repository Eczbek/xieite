# [xieite](../../xieite.md)\:\:[concepts](../../concepts.md)\:\:Hasher\<\>
Defined in header [<xieite/concepts/hasher.hpp>](../../../include/xieite/concepts/hasher.hpp)

&nbsp;

## Description
Specifies that a type is a functor for hashing values.

&nbsp;

## Synopsis
#### 1)
```cpp
template<template<typename> typename Template_, typename Argument_>
concept Hasher = requires(Template_<Argument_> hasher, Argument_ value) {
    { std::invoke(hasher, value) } -> std::convertible_to<std::size_t>;
};
```

&nbsp;

## Example
```cpp
#include <functional>
#include <print>
#include "xieite/concepts/hasher.hpp"

template<typename>
struct Nope {};

int main() {
    std::println("{}", xieite::concepts::Hasher<std::hash, int>);
    std::println("{}", xieite::concepts::Hasher<Nope, int>);
}
```
Output:
```
true
false
```
