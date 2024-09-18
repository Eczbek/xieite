# [XIEITE](../../macros.md)\_STRINGIFY...\(\)
Defined in header [<xieite/stringify.hpp>](../../../include/xieite/stringify.hpp)

&nbsp;

## Description
Converts expressions to a string literally.

&nbsp;

## Synopsis
#### 1)
```cpp
#define XIEITE_STRINGIFY(...) XIEITE_STRINGIFY_PRIMITIVE(__VA_ARGS__)
```
#### 2)
```cpp
#define XIEITE_STRINGIFY_PRIMITIVE(...) #__VA_ARGS__
```

&nbsp;

## Example
```cpp
#include <xieite/stringify.hpp>

import std;

int main() {
    std::println("{}", XIEITE_STRINGIFY(2 + 2));
}
```
Output:
```
2 + 2
```
