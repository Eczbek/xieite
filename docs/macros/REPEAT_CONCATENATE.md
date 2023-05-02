# [`XIEITE`](../../docs/macros.md)`_REPEAT_CONCATENATE`
Defined in header [`<xieite/macros/REPEAT_CONCATENATE.hpp>`](../../include/xieite/macros/REPEAT_CONCATENATE.hpp)

<br/>

Repeats the concatenation of an expression with itself. Maximum repetition count is 255.

<br/><br/>

## Synopsis

<br/><br/>

```cpp
#define XIEITE_REPEAT_CONCATENATE(expression, count) \
	XIEITE_CONCATENATE(XIEITE_INTERNAL_REPEAT_CONCATENATE_, count)(expression)
```
### Parameters
- `expression` - Any expression
- `count` - An unsigned 8-bit value

<br/><br/>

## Example
```cpp
#include <iostream>
#include <xieite/macros/REPEAT_CONCATENATE.hpp>

int main() {
	std::cout << XIEITE_REPEAT_CONCATENATE(5, 3) << '\n';
}
```
Output:
```
555
```
