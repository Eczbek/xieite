# xieite::math::approximatelyEqual
Defined in header `<xieite/math/approximatelyEqual.hpp>`

<br/>

Checks whether two numbers are almost the same, or their difference is less than their type's epsilon.

<br/><br/>

## Declarations
```cpp
template<xieite::concepts::Arithmetic Number>
[[nodiscard]]
constexpr bool approximatelyEqual(const Number value1, const Number value2) noexcept;
```

<br/><br/>

## Example
```cpp
#include <iostream> // std::boolalpha, std::cout
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
