# [`xieite`](../../README.md)`::`[`math`](../../docs/math.md)`::closestTo`
Defined in header [`<xieite/math/closestTo.hpp>`](../../include/xieite/math/closestTo.hpp)

<br/>

Selects the value closest to a target.

<br/><br/>

## Synopses

<br/>

```cpp
template<xieite::concepts::Arithmetic Number>
[[nodiscard]]
constexpr Number& closestTo(Number target, Number& a, Number& b) noexcept;
```
### Template parameters
- `Number` - An arithmetic type, satisfying `xieite::concepts::Arithmetic`
### Parameters
- `target` - A `Number` copy
- `a` - A `Number` reference
- `b` - Another `Number` reference
### Return value
- A `Number` reference to whichever of `a` or `b` has the least difference from `target`

<br/>

```cpp
template<xieite::concepts::Arithmetic Number>
[[nodiscard]]
constexpr const Number& closestTo(Number target, const Number& a, const Number& b) noexcept;
```
### Template parameters
- `Number` - An arithmetic type, satisfying `xieite::concepts::Arithmetic`
### Parameters
- `target` - A `Number` copy
- `a` - A `Number` constant reference
- `b` - Another `Number` constant reference
### Return value
- A `Number` constant reference to whichever of `a` or `b` has the least difference from `target`

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

<br/><br/>

## See also
- [`xieite::concepts::Arithmetic`](../../docs/concepts/Arithmetic.md)
