# [`XIEITE`](../../docs/macros.md)`_OBSTRUCT`
Defined in header [`<xieite/macros/OBSTRUCT.hpp>`](../../include/xieite/macros/OBSTRUCT.hpp)

<br/><br/>

## Synopsis

<br/>

```cpp
#define XIEITE_OBSTRUCT(...) \
	__VA_ARGS__ XIEITE_DEFER(XIEITE_EMPTY)()
```
### Parameters
- `...` - Any expressions

<br/><br/>

## See also
- [`XIEITE_DEFER`](../../docs/macros/DEFER.md)
- [`XIEITE_EMPTY`](../../docs/macros/EMPTY.md)
