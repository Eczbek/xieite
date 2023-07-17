# [xieite](../xieite.md)::[math](../math.md)::almostEqual
Defined in header [<xieite/math/almostEqual.hpp>](../../include/xieite/math/almostEqual.hpp)

<br/>

Checks if two values are almost equal

<br/><br/>

## Synopsis

<br/>

```cpp
template<xieite::concepts::Arithmetic Number>
[[nodiscard]]
constexpr bool almostEqual(Number value1, Number value2) noexcept;
```
### Template parameters
- `Number` - Any arithmetic type, satisfying `xieite::concepts::Arithmetic`
### Parameters
- `value1` - A `Number` copy
- `value2` - Also a `Number` copy
### Return value
- A bool

<br/><br/>

## Example
```cpp
#include <iostream>
#include <xieite/math/almostEqual.hpp>

int main() {
	const double a = 0.3;
	const double b = 0.1 + 0.2;
	
	std::cout
		<< std::boolalpha
		<< (a == b) << '\n'
		<< xieite::math::almostEqual(a, b) << '\n';
}
```
Output:
```
false
true
```
