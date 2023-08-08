# [XIEITE](../macros.md)\_REPEAT
Defined in header [<xieite/macros/REPEAT.hpp>](../../include/xieite/macros/REPEAT.hpp)

&nbsp;

## Description
Repeats an expression literally

&nbsp;

## Synopsis
```cpp
#define XIEITE__REPEAT(count, argument) XIEITE__LOOP(count, XIEITE_INTERNAL_REPEAT, , argument)
```
#### Function parameters
- `count` - An unsigned value between `0` and `255`, inclusive
- `argument` - Any expression
