# [XIEITE](../../macros.md)\_FROM\(\)
Defined in header [<xieite/from.hpp>](../../../include/xieite/from.hpp)

&nbsp;

## Description
Selects all arguments from an index, inclusively.

&nbsp;

## Synopsis
#### 1)
```cpp
#define XIEITE_FROM(index_, ...) /* ... */
```

&nbsp;

## Example
```cpp
#include <xieite/from.hpp>

XIEITE_FROM(2, a, b, c, d, e, f)
```
Preprocessor output:
```
c, d, e, f
```
