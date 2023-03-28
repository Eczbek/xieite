# xieite::math::wrap
Defined in header `<xieite/math/wrap.hpp>`

<br/>

"Wraps" a number between two limits, inclusively.

<br/><br/>

## Declarations
```cpp
template<xieite::concepts::Arithmetic Number>
[[nodiscard]]
constexpr Number wrap(Number value, Number max, Number min = 0.0) noexcept;
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
