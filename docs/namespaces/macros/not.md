# [XIEITE](../../macros.md)\_NOT\(\)
Defined in header [<xieite/not.hpp>](../../../include/xieite/not.hpp)

&nbsp;

## Description
A helper macro, expands to `1` for `0` and `0` for everything else.

&nbsp;

## Synopsis
#### 1)
```cpp
#define XIEITE_NOT($value) /* ... */
```

&nbsp;

## Example
```cpp
#include <xieite/not.hpp>

XIEITE_NOT(1)
XIEITE_NOT(true)
XIEITE_NOT(abcdef)
XIEITE_NOT(0)
```
Preprocessor output:
```
0
0
0
1
```
