# `xieite::math::approximatelyEqual`
Defined in header [`<xieite/math/approximatelyEqual.hpp>`](https://github.com/Eczbek/xieite/tree/main/include/xieite/math/approximatelyEqual.hpp)

<br/>

Checks whether two numbers' difference is below or equal to their type's epsilon.

<br/><br/>

## Synopsis

<br/>

```cpp
template<xieite::concepts::Arithmetic Number>
[[nodiscard]]
constexpr bool approximatelyEqual(Number value1, Number value2) noexcept;
```
### Template parameters
- `Number` - Any arithmetic type, satisfying `xieite::concepts::Arithmetic`
### Parameters
- `value1` - A `Number` copy
- `value2` - Also a `Number` copy
### Return value
- A `bool`

<br/><br/>

## Example
```cpp
#include <iostream>
#include <xieite/math/approximatelyEqual.hpp>

int main() {
	const double a = 0.3;
	const double b = 0.1 + 0.2;
	
	std::cout << std::boolalpha
		<< (a == b) << '\n'
		<< xieite::math::approximatelyEqual(a, b) << '\n';
}
```
Output:
```
false
true
```

<br/><br/>

## See also
- [`xieite::concepts::Arithmetic`](https://github.com/Eczbek/xieite/tree/main/docs/concepts/Arithmetic.md)
