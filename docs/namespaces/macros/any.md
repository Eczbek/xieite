# [XIEITE](../../macros.md)\_ANY\(\)
Defined in header [<xieite/any.hpp>](../../../include/xieite/any.hpp)

&nbsp;

## Description
Expands to `1` if any arguments are passed, `0` otherwise.

&nbsp;

## Synopsis
#### 1)
```cpp
#define XIEITE_ANY(...) XIEITE_NOT(__VA_OPT__(0))
```

&nbsp;

## Example
```cpp
#include <xieite/any.hpp>

XIEITE_ANY()
XIEITE_ANY(x)
XIEITE_ANY(,,,)
```
Preprocessor output:
```
0
1
1
```
