# [XIEITE](../../macros.md)\_CONCATENATE...\(\)
Defined in header [<xieite/macros/concatenate.hpp>](../../../include/xieite/macros/concatenate.hpp)

&nbsp;

## Description
A helper macro which concatenates two expressions.

&nbsp;

## Synopsis
#### 1)
```cpp
#define XIEITE_CONCATENATE_DIRECT_FORWARD(first_, second_) first_##second_
```
#### 2)
```cpp
#define XIEITE_CONCATENATE_FIRECT_REVERSE(first_, second_) second_##first_
```
#### 3)
```cpp
#define XIEITE_CONCATENATE(first_, second_) XIEITE_CONCATENATE_DIRECT_FORWARD(first_, second_)
```
#### 4)
```cpp
#define XIEITE_CONCATENATE_FIRST(first_) XIEITE_CONCATENATE_DIRECT_FORWARD(first_,
```
#### 5)
```cpp
#define XIEITE_CONCATENATE_SECOND(second_) XIEITE_CONCATENATE_DIRECT_REVERSE(second_,
```

&nbsp;

## Example
```cpp
#include <print>
#include "xieite/macros/concatenate.hpp"

int main() {
    std::println("{}", XIEITE_CONCATENATE(1, 3) + 1);
}
```
Output:
```
14
```
