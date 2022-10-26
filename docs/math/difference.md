# xieite::math::difference
Declared in `<xieite/math/difference.hpp>`
```cpp
template<std::integral N>
[[nodiscard]]
constexpr auto difference(const N a, const N b) noexcept -> std::make_unsigned_t<N>;

template<std::floating_point N>
[[nodiscard]]
constexpr N difference(const N a, const N b) noexcept;
```
Calculates the absolute difference between values.
## Example
```cpp
#include <xieite/math/difference.hpp>
#include <iostream>
#include <limits>

int main() {
	std::cout << std::numeric_limits<short>::max() << '\n'
		<< std::numeric_limits<short>::min() << '\n'
		<< xieite::math::difference(std::numeric_limits<short>::max(), std::numeric_limits<short>::min()) << '\n';
}
```
Output:
```
32767
-32768
65535
```
