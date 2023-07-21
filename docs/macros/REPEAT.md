# [XIEITE](../macros.md)\_REPEAT
Defined in header [<xieite/macros/REPEAT.hpp>](../../include/xieite/macros/REPEAT.hpp)

<br/>

Repeats an expression literally

<br/><br/>

## Synopsis

<br/>

```cpp
#define XIEITE_REPEAT(count, argument) XIEITE_LOOP(count, XIEITE_INTERNAL_REPEAT, , argument)
```
### Parameters
- `count` - An unsigned value between `0` and `255`, inclusive
- `argument` - Any expression
