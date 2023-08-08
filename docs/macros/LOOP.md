# [XIEITE](../macros.md)\_LOOP
Defined in header [<xieite/macros/LOOP.hpp>](../../include/xieite/macros/LOOP.hpp)

&nbsp;

## Description
Repeats the execution of an macro

&nbsp;

## Synopsis
```cpp
#define XIEITE__LOOP(count, macro, initial, ...) XIEITE__CONCATENATE(XIEITE_INTERNAL_LOOP_, count)(macro, initial, __VA_ARGS__)
```
#### Function parameters
- `count` - An integer of value between `0` and `255`, inclusive
- `macro` - The macro to execute. Must accept parameters:
    - `count` - The current iteration
    - `previous` - Result of the previous execution
    - `...` - Same arguments as those passed initially
- `initial` - Initial "result" to be passed to the macro
- `...` - Arguments to apply to every execution
