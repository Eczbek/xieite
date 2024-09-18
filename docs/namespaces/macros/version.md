# [XIEITE](../../macros.md)\_VERSION\_...
Defined in header [<xieite/version.hpp>](../../../include/xieite/version.hpp)

&nbsp;

## Description
Macros for xieite's current version (major, minor, patch). See header file for definitions. Also provides version comparing utilities.

&nbsp;

## Synopsis
#### 1)
```cpp
#define XIEITE_VERSION_MAJOR /* integer */
```
#### 2)
```cpp
#define XIEITE_VERSION_MINOR /* integer */
```
#### 3)
```cpp
#define XIEITE_VERSION_PATCH /* integer */
```
#### 4)
```cpp
#define XIEITE_VERSION_EQUAL(major, minor, patch) /* boolean */
```
#### 5)
```cpp
#define XIEITE_VERSION_LEAST(major, minor, patch) /* boolean */
```
#### 6)
```cpp
#define XIEITE_VERSION_MOST(major, minor, patch) /* boolean */
```

&nbsp;

## Example
```cpp
#include <xieite/version.hpp>

import std;

int main() {
    std::println("{}", XIEITE_VERSION_LEAST(6, 56, 0));
}
```
Posible output:
```
true
```
