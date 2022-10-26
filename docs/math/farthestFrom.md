# xieite::math::farthestFrom
Declared in `<xieite/math/farthestFrom.hpp>`
```cpp
template<xieite::concepts::Arithmetic N>
[[nodiscard]]
constexpr N& farthestFrom(const N target, const N a, const N b) noexcept;
```
Gets the value farthest from a target.
## Example
```cpp
#include <xieite/math/farthestFrom.hpp>
#include <iostream>

int main() {
	std::cout << xieite::math::farthestFrom(0, 5, -1) << '\n';
}
```
Output:
```
5
```
