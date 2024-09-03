# [XIEITE](../../macros.md)\_ASCII\_SUPPORT
Defined in header ["ascii_support.hpp"](../../../src/macros/ascii_support.hpp)

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
#include "ascii_support.hpp"

import std;

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
