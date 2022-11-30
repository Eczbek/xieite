# xieite::math::approxEqual
Declared in `<xieite/math/approxEqual.hpp>`

<br/>

Checks whether two numbers are almost the same.

<br/><br/>

## Declaration
```cpp
template<xieite::concepts::Arithmetic N>
[[nodiscard]]
constexpr bool approxEqual(const N value1, const N value2) noexcept;
```

<br/><br/>

## Example
```cpp
#include <iostream>
#include <xieite/math/approxEqual.hpp>

int main() {
	const double a = 0.3;
	const double b = 0.1 + 0.2;
	
	std::cout << std::boolalpha
		<< (a == b) << '\n'
		<< xieite::math::approxEqual(a, b) << '\n';
}
```
Output:
```
false
true
```
