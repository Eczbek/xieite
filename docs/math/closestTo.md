# xieite::math::closestTo
Declared in `<xieite/math/closestTo.hpp>`

<br/>

Selects the value closest to a target.

<br/><br/>

## Declaration
```cpp
template<xieite::concepts::Arithmetic N>
[[nodiscard]]
constexpr N& closestTo(const N target, const N a, const N b) noexcept;
```

<br/><br/>

## Example
```cpp
#include <iostream>
#include <xieite/math/closestTo.hpp>

int main() {
	std::cout << xieite::math::closestTo(0, 5, -1) << '\n';
}
```
Output:
```
-1
```
