# [XIEITE](../../macros.md)\_REVERSE\(\)
Defined in header [<xieite/reverse.hpp>](../../../include/xieite/reverse.hpp)

&nbsp;

## Description
Reverses arguments.

&nbsp;

## Synopsis
#### 1)
```cpp
#define XIEITE_REVERSE(...) /* ... */
```

&nbsp;

## Example
```cpp
#include <xieite/reverse.hpp>

XIEITE_REVERSE(1, 2, 3, 4, 5)
```
Preprocessor output:
```
5, 4, 3, 2, 1
```
