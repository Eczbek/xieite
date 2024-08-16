# [xieite](../../xieite.md)\:\:[functors](../../functors.md)\:\:templatify\<\>\(\)
Defined in header [<xieite/functors/templatify.hpp>](../../../include/xieite/functors/templatify.hpp)

&nbsp;

## Description
Performs a slight bit of spacetime manipulation. `Functor` must be default-constructible.

&nbsp;

## Synopsis
#### 1)
```cpp
template<template<std::uint8_t> typename Functor>
constexpr void templatify(std::uint8_t value) noexcept;
```

&nbsp;

## Example
```cpp
#include <cstdint>
#include <print>
#include "xieite/functors/templatify.hpp"

template<std::uint8_t value>
struct Functor {
    void operator()() {
        std::println("{}", value);
    }
};

int main() {
    xieite::functors::templatify<Functor>(14);
}
```
Output:
```
14
```
