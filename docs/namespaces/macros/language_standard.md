# [XIEITE](../../macros.md)\_LANGUAGE\_STANDARD\_...
Defined in header [<xieite/language_standard.hpp>](../../../include/xieite/language_standard.hpp)

&nbsp;

## Description
Macros for identifying the current C or C++ language standard.

&nbsp;

## Synopsis
#### 1)
```cpp
#define XIEITE_LANGUAGE_STANDARD_C_1978 /* boolean */
```
#### 2)
```cpp
#define XIEITE_LANGUAGE_STANDARD_C_1989 /* boolean */
```
#### 3)
```cpp
#define XIEITE_LANGUAGE_STANDARD_C_1990 /* boolean */
```
#### 4)
```cpp
#define XIEITE_LANGUAGE_STANDARD_C_1994 /* boolean */
```
#### 5)
```cpp
#define XIEITE_LANGUAGE_STANDARD_C_1999 /* boolean */
```
#### 6)
```cpp
#define XIEITE_LANGUAGE_STANDARD_C_2011 /* boolean */
```
#### 7)
```cpp
#define XIEITE_LANGUAGE_STANDARD_C_2018 /* boolean */
```
#### 8)
```cpp
#define XIEITE_LANGUAGE_STANDARD_C_2023 /* boolean */
```
#### 9)
```cpp
#define XIEITE_LANGUAGE_STANDARD_CPP_1998 /* boolean */
```
#### 10)
```cpp
#define XIEITE_LANGUAGE_STANDARD_CPP_2011 /* boolean */
```
#### 11)
```cpp
#define XIEITE_LANGUAGE_STANDARD_CPP_2014 /* boolean */
```
#### 12)
```cpp
#define XIEITE_LANGUAGE_STANDARD_CPP_2017 /* boolean */
```
#### 13)
```cpp
#define XIEITE_LANGUAGE_STANDARD_CPP_2020 /* boolean */
```
#### 14)
```cpp
#define XIEITE_LANGUAGE_STANDARD_CPP_2023 /* boolean */
```
#### 15)
```cpp
#define XIEITE_LANGUAGE_STANDARD_CPP_CLI /* boolean */
```
#### 16)
```cpp
#define XIEITE_LANGUAGE_STANDARD_CPP_EMBEDDED /* boolean */
```

&nbsp;

## Example
```cpp
#include <xieite/language_standard.hpp>

#if XIEITE_LANGUAGE_STANDARD_CPP_2023
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
