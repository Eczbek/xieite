# [XIEITE](../../macros.md)\_LANGUAGE\_...
Defined in header [<xieite/language.hpp>](../../../include/xieite/language.hpp)

&nbsp;

## Description
Macros for identifying the current C or C++ language standard. Also provides macros for detecting the presence of C++/CLI, C++/CX, C++/WinRT, Embedded C++, CUDA C/C++, and Objective C.

&nbsp;

## Synopsis
See header for definitions.

&nbsp;

## Example
```cpp
#include <xieite/language.hpp>

#if XIEITE_LANGUAGE_CPP >= 2023
#    include <print>

int main() {
    std::println("Hello, world!");
}

#else
#    include <iostream>

int main() {
    std::cout << "Hello, world!\n";
}

#endif
```
Output:
```
Hello, world!
```
