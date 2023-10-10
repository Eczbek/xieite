# [XIEITE](../../macros.md)\_LOOP
Defined in header [<xieite/macros/loop.hpp>](../../include/xieite/macros/loop.hpp)

&nbsp;

## Description
Repeats the execution of an macro.

&nbsp;

## Synopsis
```cpp
#define XIEITE_LOOP(count, macro, initial, ...) XIEITE_CONCATENATE(XIEITE_LOOP_INTERNAL_, count)(macro, initial, __VA_ARGS__)
```
