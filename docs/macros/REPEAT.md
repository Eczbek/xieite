# `XIEITE_REPEAT`
Defined in header [`<xieite/macros/REPEAT.hpp>`](https://github.com/Eczbek/xieite/tree/main/include/xieite/macros/REPEAT.hpp)

<br/>

Repeats an expression literally. Maximum repetition count is 255.

<br/><br/>

## Synopsis

<br/>

```cpp
#define XIEITE_REPEAT(expression, count) \
	XIEITE_CONCATENATE(XIEITE_REPEAT_, count)(expression)
```
### Parameters
- `expression` - Any expression
- `count` - An unsigned 8-bit value
