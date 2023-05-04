# [`XIEITE`](../../docs/macros.md)`_REPEAT`
Defined in header [`<xieite/macros/REPEAT.hpp>`](../../include/xieite/macros/REPEAT.hpp)

<br/>

Repeats an expression literally.

<br/><br/>

## Synopsis

<br/><br/>

```cpp
#define XIEITE_REPEAT(count, expression) \
	XIEITE_LOOP(count, XIEITE_INTERNAL_REPEAT, , expression)
```
### Parameters
- `count` - An unsigned value between 0 and 32767, inclusively
- `expression` - Any expression
