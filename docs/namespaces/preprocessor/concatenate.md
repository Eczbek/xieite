# [XIEITE](../../macros.md)\_CONCATENATE...\(\)
Defined in header [<xieite/concatenate.hpp>](../../../include/xieite/concatenate.hpp)

&nbsp;

## Description
Helper macros which concatenate two values.

&nbsp;

## Synopsis
#### 1)
```cpp
#define XIEITE_CONCATENATE(first_, ...) XIEITE_CONCATENATE_PRIMITIVE(first_, __VA_ARGS__)
```
#### 2)
```cpp
#define XIEITE_CONCATENATE_REVERSE(first_, ...) XIEITE_CONCATENATE_PRIMITIVE_REVERSE(first_, __VA_ARGS__)
```
#### 3)
```cpp
#define XIEITE_CONCATENATE_PRIMITIVE(first_, ...) first_##__VA_ARGS__
```
#### 4)
```cpp
#define XIEITE_CONCATENATE_PRIMITIVE_REVERSE(first_, ...) __VA_ARGS__##first_
```
#### 5)
```cpp
#define XIEITE_CONCATENATE_FIRST(first_) XIEITE_CONCATENATE_PRIMITIVE(first_,
```
#### 6)
```cpp
#define XIEITE_CONCATENATE_SECOND(second_) XIEITE_CONCATENATE_PRIMITIVE_REVERSE(second_,
```

&nbsp;

## Example
```cpp
#include <xieite/concatenate.hpp>

import std;

int main() {
    std::println("{}", XIEITE_CONCATENATE(1, 3) + 1);
}
```
Output:
```
14
```
