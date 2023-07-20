# [xieite](../xieite.md)::[math](../math.md)::closestTo
Defined in header [<xieite/math/closestTo.hpp>](../../include/xieite/math/closestTo.hpp)

<br/>

Selects the value closest to a target

<br/><br/>

## Synopses

<br/><br/>

```cpp
template<xieite::concepts::Arithmetic Number1, xieite::concepts::Arithmetic Number2, xieite::concepts::Arithmetic Number3>
[[nodiscard]]
constexpr xieite::math::Result<Number1, Number2, Number3>& closestTo(const Number1 target, Number2& value1, Number3& value2) noexcept;
```
### Template parameters
- `Number1` - A type satisfying `xieite::concepts::Arithmetic`
- `Number2` - A type satisfying `xieite::concepts::Arithmetic`
- `Number3` - A type satisfying `xieite::concepts::Arithmetic`
### Parameters
- `target` - A `Number1`
- `value1` - A `Number2` reference
- `value2` - A `Number3` reference
### Return value
- A `xieite::math::Result` of `Number`, reference to whichever of `value1` or `value2` has the least difference from `target`

<br/><br/>

```cpp
template<xieite::concepts::Arithmetic Number>
[[nodiscard]]
constexpr const Number& closestTo(Number target, const Number& value1, const Number& value2) noexcept;
```
### Template parameters
- `Number` - An arithmetic type satisfying `xieite::concepts::Arithmetic`
### Parameters
- `target` - A `Number`
- `value1` - A constant `Number` reference
- `value2` - A constant `Number` reference
### Return value
- A constant `xieite::math::Result` of `Number1`, `Number2`, and `Number3`, reference to whichever of `value1` or `value2` has the least difference from `target`

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
