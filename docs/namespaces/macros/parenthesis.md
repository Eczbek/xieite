# [XIEITE](../../macros.md)\_PARENTHESIS\_...\(\)
Defined in header [<xieite/macros/parenthesis.hpp>](../../../include/xieite/macros/parenthesis.hpp)

&nbsp;

## Description
Helper macros which expand to left and right parentheses.

&nbsp;

## Synopsis
#### 1)
```cpp
#define XIEITE_PARENTHESIS_LEFT(...) (
```
#### 2)
```cpp
#define XIEITE_PARENTHESIS_RIGHT(...) )
```

&nbsp;

## Example
```cpp
#include <print>
#include "xieite/macros/parenthesis.hpp"

int main() {
    std::println XIEITE_PARENTHESIS_LEFT() "Hello, world!" XIEITE_PARENTHESIS_RIGHT();
}
```
Output:
```
Hello, world!
```
