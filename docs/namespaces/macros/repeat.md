# [XIEITE](../../macros.md)\_\_REPEAT
Defined in header [<xieite/macros/repeat.hpp>](../../include/xieite/macros/repeat.hpp)

&nbsp;

## Description
Repeats an expression literally.

&nbsp;

## Synopsis
```cpp
#define XIEITE__REPEAT(count, argument) XIEITE__LOOP(count, XIEITE_INTERNAL__REPEAT, , argument)
```
