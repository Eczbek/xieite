# [XIEITE](../../macros.md)\_CONCATENATE...\(\)
Defined in header [<xieite/concatenate.hpp>](../../../include/xieite/concatenate.hpp)

&nbsp;

## Description
A helper macro which concatenates two expressions.

&nbsp;

## Synopsis
#### 1)
```cpp
#define XIEITE_CONCATENATE_DIRECT_FORWARD($first, $second) $first##$second
```
#### 2)
```cpp
#define XIEITE_CONCATENATE_DIRECT_REVERSE($first, $second) $second##$first
```
#### 3)
```cpp
#define XIEITE_CONCATENATE($first, $second) XIEITE_CONCATENATE_DIRECT_FORWARD($first, $second)
```
#### 4)
```cpp
#define XIEITE_CONCATENATE_FIRST($first) XIEITE_CONCATENATE_DIRECT_FORWARD($first,
```
#### 5)
```cpp
#define XIEITE_CONCATENATE_SECOND($second) XIEITE_CONCATENATE_DIRECT_REVERSE($second,
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
