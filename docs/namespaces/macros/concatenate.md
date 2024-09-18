# [XIEITE](../../macros.md)\_CONCATENATE...\(\)
Defined in header [<xieite/concatenate.hpp>](../../../include/xieite/concatenate.hpp)

&nbsp;

## Description
Helper macros which concatenate two values.

&nbsp;

## Synopsis
#### 1)
```cpp
#define XIEITE_CONCATENATE($first, $second) XIEITE_CONCATENATE_PRIMITIVE($first, $second)
```
#### 2)
```cpp
#define XIEITE_CONCATENATE_REVERSE($first, $second) XIEITE_CONCATENATE_PRIMITIVE_REVERSE($first, $second)
```
#### 3)
```cpp
#define XIEITE_CONCATENATE_PRIMITIVE($first, $second) $first##$second
```
#### 4)
```cpp
#define XIEITE_CONCATENATE_PRIMITIVE_REVERSE($first, $second) $second##$first
```
#### 5)
```cpp
#define XIEITE_CONCATENATE_FIRST($first) XIEITE_CONCATENATE_PRIMITIVE($first,
```
#### 6)
```cpp
#define XIEITE_CONCATENATE_SECOND($second) XIEITE_CONCATENATE_PRIMITIVE_REVERSE($second,
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
