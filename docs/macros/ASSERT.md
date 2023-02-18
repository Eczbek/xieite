# XIEITE_ASSERT
Declared in `<xieite/macros/ASSERT.hpp>`

<br/>

Asserts an expression, either at compile-time or run-time.

<br/><br/>

## Definition
```cpp
#define XIEITE_ASSERT(booleanExpression, stringLiteral) \
	static_assert((__builtin_constant_p((booleanExpression)) ? (booleanExpression) : true), stringLiteral); \
	if !consteval { \
		if (!(booleanExpression)) \
			throw std::runtime_error(stringLiteral); \
	}
```
