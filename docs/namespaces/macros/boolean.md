# [XIEITE](../../macros.md)\_BOOLEAN\(\)
Defined in header [<xieite/boolean.hpp>](../../../include/xieite/boolean.hpp)

&nbsp;

## Description
Expands to `1` for any value except for `0`.

&nbsp;

## Synopsis
#### 1)
```cpp
#define XIEITE_BOOLEAN($value) /* ... */
```

&nbsp;

## Example
```cpp
#include <xieite/boolean.hpp>

XIEITE_BOOLEAN(1)
XIEITE_BOOLEAN(true)
XIEITE_BOOLEAN(abcdef)
XIEITE_BOOLEAN(0)
```
Preprocessor output:
```
1
1
1
0
```
