# xieite::math::closestTo
Defined in header `<xieite/math/closestTo.hpp>`

<br/>

Selects the value closest to a target.

<br/><br/>

## Declarations
```cpp
template<xieite::concepts::Arithmetic Number>
[[nodiscard]]
constexpr Number& closestTo(const Number target, Number& a, Number& b) noexcept;
```
```cpp
template<xieite::concepts::Arithmetic Number>
[[nodiscard]]
constexpr Number closestTo(const Number target, const Number& a, const Number& b) noexcept;
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
