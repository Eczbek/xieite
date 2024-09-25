# [XIEITE](../../macros.md)\_UNTIL\(\)
Defined in header [<xieite/until.hpp>](../../../include/xieite/until.hpp)

&nbsp;

## Description
Selects all arguments until an index, exclusively.

&nbsp;

## Synopsis
#### 1)
```cpp
#define XIEITE_UNTIL(index_, ...) /* ... */
```

&nbsp;

## Example
```cpp
#include <xieite/until.hpp>

XIEITE_UNTIL(4, a, b, c, d, e, f)
```
Preprocessor output:
```
a, b, c, d
```
