# [XIEITE](../../macros.md)\_WHEN\(\)
Defined in header [<xieite/when.hpp>](../../../include/xieite/when.hpp)

&nbsp;

## Description
A utility for `XIEITE_IF()`.

&nbsp;

## Synopsis
#### 1)
```cpp
#define XIEITE_WHEN(value_) XIEITE_IF(value_)(XIEITE_SCAN, XIEITE_EAT)
```

&nbsp;

## Example
```cpp
#include <xieite/when.hpp>

XIEITE_WHEN(0)(abc)
XIEITE_WHEN(1)(xyz)
```
Preprocessor output:
```

xyz
```
