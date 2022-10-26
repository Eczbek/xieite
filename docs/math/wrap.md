# xieite::math::wrap
Declared in `<xieite/math/wrap.hpp>`
```cpp
template<xieite::concepts::Arithmetic N>
[[nodiscard]]
constexpr N wrap(const N value, const N max, const N min = 0) noexcept;
```
Wraps a number between two others.
<br/>
The limit `max` is exclusive.
## Example
```cpp
#include <xieite/math/wrap.hpp>
#include <iostream>

int main() {
	std::cout << xieite::math::wrap(23, 4, -2) << '\n';
}
```
Output:
```
-1
```
