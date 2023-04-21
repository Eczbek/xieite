# `xieite::math::farthestFrom`
Defined in header [`<xieite/math/farthestFrom.hpp>`](../../include/xieite/math/farthestFrom.hpp)

<br/>

Selects the value farthest from a target.

<br/><br/>

## Synopses

<br/>

```cpp
template<xieite::concepts::Arithmetic Number>
[[nodiscard]]
constexpr Number& farthestFrom(Number target, Number& a, Number& b) noexcept;
```
### Template parameters
- `Number` - Any arithmetic type, satisfying `xieite::concepts::Arithmetic`
### Parameters
- `target` - A `Number` copy
- `a` - A `Number` reference
- `b` - A `Number` reference
### Return value
- A `Number` reference to whichever of `a` and `b` has the greatest difference from `target`

<br/>

```cpp
template<xieite::concepts::Arithmetic Number>
[[nodiscard]]
constexpr Number farthestFrom(Number target, const Number& a, const Number& b) noexcept;
```
### Template parameters
- `Number` - Any arithmetic type, satisfying `xieite::concepts::Arithmetic`
### Parameters
- `target` - A `Number` copy
- `a` - A `Number` constant reference
- `b` - Also a `Number` constant reference
### Return value
- A `Number` constant reference to whichever of `a` and `b` has the greatest difference from `target`

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

<br/><br/>

## See also
- [`xieite::concepts::Arithmetic`](../../docs/concepts/Arithmetic.md)
