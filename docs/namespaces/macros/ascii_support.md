# [XIEITE](../../macros.md)\_ASCII\_SUPPORT
Defined in header [<xieite/macros/ascii_support.hpp>](../../../include/xieite/macros/ascii_support.hpp)

&nbsp;

## Description
Checks if the compiler supports ASCII stuff.

&nbsp;

## Synopsis
#### 1)
```cpp
#define XIEITE_ASCII_SUPPORT /* boolean */
```

&nbsp;

## Example
```cpp
#include <cstddef>
#include <print>
#include <string_view>
#include "xieite/macros/ascii_support.hpp"

char getAlphabetLetter(std::size_t n) {
#if XIEITE_ASCII_SUPPORT
    return static_cast<char>('a' + n);
#else
    static constexpr std::string_view alphabet = "abcdefghijklmnopqrstuvwxyz";
    return alphabet.at(n);
#endif
}

int main() {
    std::println("{}", getAlphabetLetter(7));
}
```
Output:
```
h
```
