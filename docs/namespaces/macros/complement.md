# [XIEITE](../../macros.md)\_COMPLEMENT\(\)
Defined in header [<xieite/complement.hpp>](../../../include/xieite/complement.hpp)

&nbsp;

## Description
Expands to `1` for `0` and `0` for `1`.

&nbsp;

## Synopsis
#### 1)
```cpp
#define XIEITE_COMPLEMENT($boolean) /* ... */
```

&nbsp;

## Example
```cpp
#include <xieite/complement.hpp>

XIEITE_COMPLEMENT(0)
XIEITE_COMPLEMENT(1)
```
Preprocessor output:
```
1
0
```
