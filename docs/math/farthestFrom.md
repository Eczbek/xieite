# xieite::math::farthestFrom
Defined in header `<xieite/math/farthestFrom.hpp>`

<br/>

Selects the value farthest from a target.

<br/><br/>

## Declarations
```cpp
template<xieite::concepts::Arithmetic Number>
[[nodiscard]]
constexpr Number& farthestFrom(const Number target, Number& a, Number& b) noexcept;

template<xieite::concepts::Arithmetic Number>
[[nodiscard]]
constexpr Number farthestFrom(const Number target, const Number& a, const Number& b) noexcept;
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
