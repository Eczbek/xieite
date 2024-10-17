# [XIEITE](../../macros.md)\_LANGUAGE\_...
Defined in header [<xieite/language.hpp>](../../../include/xieite/language.hpp)

&nbsp;

## Description
Macros for identifying the current C or C++ language standard. Also provides macros for detecting the presence (but not versions of) C++/CLI, C++/CX, C++/WinRT, and Embedded C++.

&nbsp;

## Synopsis
#### 1)
```cpp
#define XIEITE_LANGUAGE_C /* integer */
```
#### 2)
```cpp
#define XIEITE_LANGUAGE_CPP /* integer */
```
#### 3)
```cpp
#define XIEITE_LANGUAGE_CPP_CLI /* boolean */
```
#### 4)
```cpp
#define XIEITE_LANGUAGE_CPP_CX /* boolean */
```
#### 5)
```cpp
#define XIEITE_LANGUAGE_CPP_EMBEDDED /* boolean */
```
#### 6)
```cpp
#define XIEITE_LANGUAGE_CPP_WINRT /* boolean */
```
#### 7)
```cpp
#define XIEITE_LANGUAGE_C_/* 1978..2023 */ /* integer */
```
#### 8)
```cpp
#define XIEITE_LANGUAGE_CPP_/* 1998..2026 */ /* integer */
```

&nbsp;

## Example
```cpp
#include <xieite/language.hpp>

#if XIEITE_LANGUAGE_CPP >= XIEITE_LANGUAGE_CPP_2023
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
