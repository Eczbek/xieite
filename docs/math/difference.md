# xieite::math::difference
Declared in `<xieite/math/difference.hpp>`

<br/>

Calculates the absolute difference between values.

<br/><br/>

## Declarations
```cpp
template<std::integral N>
[[nodiscard]]
constexpr std::make_unsigned_t<N> difference(const N a, const N b) noexcept;
```
```cpp
template<std::floating_point N>
[[nodiscard]]
constexpr N difference(const N a, const N b) noexcept;
```

<br/><br/>

## Example
```cpp
#include <cstdint>
#include <iostream>
#include <limits>
#include <xieite/math/difference.hpp>

int main() {
	const std::int8_t min = std::numeric_limits<std::int8_t>::min();
	const std::int8_t max = std::numeric_limits<std::int8_t>::max();

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
