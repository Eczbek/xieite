# [XIEITE](../../macros.md)\_VERSION\_...
Defined in header [<xieite/macros/version.hpp>](../../../include/xieite/macros/version.hpp)

&nbsp;

## Description
Macros for xieite's current version (major, minor, patch). See header file for definitions.

Also provides version checking utilities:

&nbsp;

## Synopsis
#### 1)
```cpp
#define XIEITE_VERSION_LEAST(major, minor, patch) /* boolean */
```
#### 2)
```cpp
#define XIEITE_VERSION_MOST(major, minor, patch) /* boolean */
```

&nbsp;

## Example
```cpp
#include <print>
#include "xieite/macros/version.hpp"

int main() {
    std::println("{}", XIEITE_VERSION_LEAST(6, 56, 0));
}
```
Posible output:
```
true
```
