# xieite::math::closestTo
Declared in `<xieite/math/closestTo.hpp>`
```cpp
template<xieite::concepts::Arithmetic N>
[[nodiscard]]
constexpr N& closestTo(const N target, const N a, const N b) noexcept;
```
Gets the value closest to a target.
## Example
```cpp
#include <xieite/math/closestTo.hpp>
#include <iostream>

int main() {
	std::cout << xieite::math::closestTo(0, 5, -1) << '\n';
}
```
Output:
```
-1
```
