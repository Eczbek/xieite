# [xieite](../xieite.md)::[math](../math.md)::farthestFrom
Defined in header [<xieite/math/farthestFrom.hpp>](../../include/xieite/math/farthestFrom.hpp)

<br/>

Selects the value farthest from a target

<br/><br/>

## Synopses

<br/><br/>

```cpp
template<xieite::concepts::Arithmetic Number1, xieite::concepts::Arithmetic Number2, xieite::concepts::Arithmetic Number3>
[[nodiscard]]
constexpr xieite::math::Result<Number1, Number2, Number3>& farthestFrom(const Number1 target, Number2& value1, Number3& value2) noexcept;
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
- A `xieite::math::Result` of `Number1`, `Number2`, and `Number3`, reference to whichever of `value1` and `value2` has the greatest difference from target

<br/><br/>

```cpp
template<xieite::concepts::Arithmetic Number1, xieite::concepts::Arithmetic Number2, xieite::concepts::Number3>
[[nodiscard]]
constexpr const xieite::math::Result<Number1, Number2, Number3>& farthestFrom(const Number1 target, const Number2& value1, const Number3& value2) noexcept;
```
### Template parameters
- `Number1` - A type satisfying `xieite::concepts::Arithmetic`
- `Number2` - A type satisfying `xieite::concepts::Arithmetic`
- `Number3` - A type satisfying `xieite::concepts::Arithmetic`
### Parameters
- `target` - A `Number1`
- `value1` - A `Number2` constant reference
- `value2` - Also a `Number3` constant reference
### Return value
- A `xieite::math::Result` of `Number1`, `Number2`, and `Number3`, constant reference to whichever of `value1` and `value2` has the greatest difference from target

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
