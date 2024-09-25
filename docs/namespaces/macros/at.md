# [XIEITE](../../macros.md)\_AT\(\)
Defined in header [<xieite/at.hpp>](../../../include/xieite/at.hpp)

&nbsp;

## Description
Selects an argument by index.

&nbsp;

## Synopsis
#### 1)
```cpp
#define XIEITE_AT(index_, ...) /* ... */
```

&nbsp;

## Example
```cpp
#include <xieite/at.hpp>

XIEITE_AT(5, a, b, c, d, e, f)
```
Preprocessor output:
```
f
```
