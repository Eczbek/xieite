# [XIEITE](../macros.md)_DEFER
Defined in header [<xieite/macros/DEFER.hpp>](../../include/xieite/macros/DEFER.hpp)

<br/>

Defers expressions for later evaluation

<br/><br/>

## Synopsis

<br/>

```cpp
#define XIEITE_DEFER(...) \
	__VA_ARGS__ XIEITE_EMPTY()
```
### Parameters
- `...` - Any expressions
