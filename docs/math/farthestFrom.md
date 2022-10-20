# gcufl::math::farthestFrom
Declared in `<gcufl/math/farthestFrom.hpp>`
```cpp
template<gcufl::concepts::Arithmetic N>
[[nodiscard]]
constexpr N& farthestFrom(const N target, const N a, const N b) noexcept;
```
Gets the value farthest from a target.
## Example
```cpp
#include <gcufl/math/farthestFrom.hpp>
#include <iostream>

int main() {
	std::cout << gcufl::math::farthestFrom(0, 5, -1) << '\n';
}
```
Output:
```
5
```
