# [`XIEITE`](../../docs/macros.md)`_REPEAT`
Defined in header [`<xieite/macros/REPEAT.hpp>`](../../include/xieite/macros/REPEAT.hpp)

<br/>

Repeats an expression literally. Maximum repetition count is 255.

<br/><br/>

## Synopsis

<br/><br/>

```cpp
#define XIEITE_REPEAT(expression, count) \
	XIEITE_CONCATENATE(XIEITE_INTERNAL_REPEAT_, count)(expression)
```
### Parameters
- `expression` - Any expression
- `count` - An unsigned 8-bit value
