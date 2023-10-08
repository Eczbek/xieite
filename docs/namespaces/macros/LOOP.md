# [XIEITE](../macros.md)\_\_LOOP
Defined in header [<xieite/macros/LOOP.hpp>](../../include/xieite/macros/LOOP.hpp)

&nbsp;

## Description
Repeats the execution of an macro.

&nbsp;

## Synopsis
```cpp
#define XIEITE__LOOP(count, macro, initial, ...) XIEITE__CONCATENATE(XIEITE_INTERNAL__LOOP_, count)(macro, initial, __VA_ARGS__)
```
