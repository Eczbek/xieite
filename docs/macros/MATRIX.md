# [XIEITE](../macros.md)\_MATRIX
Defined in header [<xieite/macros/MATRIX.hpp>](../../include/xieite/macros/MATRIX.hpp)

&nbsp;

## Description
Creates a multidimensional vector matrix

&nbsp;

## Synopsis
```cpp
#define XIEITE__MATRIX(type, dimensions) XIEITE__REPEAT(dimensions, std::vector<) type XIEITE__REPEAT(dimensions, >)
```
#### Function parameters
- `type` - Any typename
- `dimensions` - Any integer between `0` and `255`, inclusive

&nbsp;

## Example
```cpp
#include <xieite/macros/MATRIX.hpp>

int main() {
    XIEITE__MATRIX(int, 3) matrix;
}
```
Result:
```cpp
int main() {
    std::vector<std::vector<std::vector<int>>> matrix;
}
```
