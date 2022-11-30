# xieite::math::wrap
Declared in `<xieite/math/wrap.hpp>`

<br/>

"Wraps" a number between two limits, like modulo but can have any bottom limit.

<br/><br/>

## Declaration
```cpp
template<xieite::concepts::Arithmetic N>
[[nodiscard]]
constexpr N wrap(const N value, const N max, const N min = 0) noexcept;
```

<br/><br/>

## Example
```cpp
#include <iostream>
#include <xieite/math/wrap.hpp>

int main() {
	std::cout << xieite::math::wrap(23, 4, -2) << '\n';
}
```
Output:
```
-1
```
