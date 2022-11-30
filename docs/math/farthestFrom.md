# xieite::math::farthestFrom
Declared in `<xieite/math/farthestFrom.hpp>`

<br/>

Gets the value farthest from a target.

<br/><br/>

## Declaration
```cpp
template<xieite::concepts::Arithmetic N>
[[nodiscard]]
constexpr N& farthestFrom(const N target, const N a, const N b) noexcept;
```

<br/><br/>

## Example
```cpp
#include <iostream>
#include <xieite/math/farthestFrom.hpp>

int main() {
	std::cout << xieite::math::farthestFrom(0, 5, -1) << '\n';
}
```
Output:
```
5
```
