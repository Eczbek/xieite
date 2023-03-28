# xieite::math::difference
Defined in header `<xieite/math/difference.hpp>`

<br/>

Calculates the absolute difference between two values. Handles some edge cases.

<br/><br/>

## Declarations
```cpp
template<std::integral Integral>
[[nodiscard]]
constexpr std::make_unsigned<Integral> difference(Integral a, Integral b) noexcept;
```
```cpp
template<std::floating_point FloatingPoint>
[[nodiscard]]
constexpr FloatingPoint difference(FloatingPoint a, FloatingPoint b) noexcept;
```

<br/><br/>

## Example
```cpp
#include <cstdint>
#include <iostream>
#include <limits>
#include <xieite/math/difference.hpp>

int main() {
	std::int8_t min = std::numeric_limits<std::int8_t>::min();
	std::int8_t max = std::numeric_limits<std::int8_t>::max();

	std::cout
		<< min << '\n'
		<< max << '\n'
		<< xieite::math::difference(min, max) << '\n';
}
```
Output:
```
-128
127
255
```
