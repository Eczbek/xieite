# gcufl::math::closestTo
Declared in `<gcufl/math/closestTo.hpp>`
```cpp
template<gcufl::concepts::Arithmetic N>
[[nodiscard]]
constexpr N closestTo(const N target, const N a, const N b) noexcept {
	return (a >= target)
		? (b >= target)
			? (a < b)
				? a
				: b
			: (gcufl::math::difference(target, a) < gcufl::math::difference(target, b))
				? a
				: b
		: (b < target)
			? (a > b)
				? a
				: b
			: (gcufl::math::difference(target, a) > gcufl::math::difference(target, b))
				? a
				: b;
}
```
Gets the value closest to a target.
## Example
```cpp
#include <gcufl/math/closestTo.hpp>
#include <iostream>

int main() {
	std::cout << gcufl::math::closestTo(0, 5, -1) << '\n';
}
```
Output:
```
-1
```
