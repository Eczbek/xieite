# [`XIEITE`](../../docs/macros.md)`_ASSERT`
Defined in header [`<xieite/macros/ASSERT.hpp>`](../../include/xieite/macros/ASSERT.hpp)

<br/>

Asserts an expression, either at compile-time or run-time.

<br/><br/>

## Synopsis

<br/><br/>

```cpp
#define XIEITE_ASSERT(booleanExpression, stringLiteral) \
	static_assert((__builtin_constant_p((booleanExpression)) ? (booleanExpression) : true), stringLiteral); \
	if !consteval { \
		if (!(booleanExpression)) { \
			throw std::runtime_error(stringLiteral); \
		} \
	}
```
### Parameters
- `booleanExpression` - Any expression which becomes a `bool`ean value
- `stringLiteral` - Any string literal
