# [xieite](../xieite.md)::[math](../math.md)::closestTo
Defined in header [<xieite/math/closestTo.hpp>](../../include/xieite/math/closestTo.hpp)

<br/>

Selects the value closest to a target

<br/><br/>

## Synopses

<br/><br/>

```cpp
template<xieite::concepts::Arithmetic Arithmetic1, xieite::concepts::Arithmetic Arithmetic2, xieite::concepts::Arithmetic Arithmetic3>
[[nodiscard]]
constexpr xieite::math::Result<Arithmetic1, Arithmetic2, Arithmetic3>& closestTo(const Arithmetic1 target, Arithmetic2& value1, Arithmetic3& value2) noexcept;
```
### Template parameters
- `Arithmetic1` - A type satisfying `xieite::concepts::Arithmetic`
- `Arithmetic2` - A type satisfying `xieite::concepts::Arithmetic`
- `Arithmetic3` - A type satisfying `xieite::concepts::Arithmetic`
### Parameters
- `target` - An `Arithmetic1`
- `value1` - An `Arithmetic2` reference
- `value2` - An `Arithmetic3` reference
### Return value
- A `xieite::math::Result` of `Arithmetic`, reference to whichever of `value1` or `value2` has the least difference from `target`

<br/><br/>

```cpp
template<xieite::concepts::Arithmetic Arithmetic1, xieite::concepts::Arithmetic Arithmetic2, xieite::concepts::Arithmetic Arithmetic3>
[[nodiscard]]
constexpr const xieite::math::Result<Arithmetic1, Arithmetic2, Arithmetic3>& closestTo(const Arithmetic1 target, const Arithmetic2& value1, const Arithmetic3& value2) noexcept;
```
### Template parameters
- `Arithmetic1` - A type satisfying `xieite::concepts::Arithmetic`
- `Arithmetic2` - A type satisfying `xieite::concepts::Arithmetic`
- `Arithmetic3` - A type satisfying `xieite::concepts::Arithmetic`
### Parameters
- `target` - An `Arithmetic1`
- `value1` - A constant `Arithmetic2` reference
- `value2` - A constant `Arithmetic3` reference
### Return value
- A constant `xieite::math::Result` of `Arithmetic1`, `Arithmetic2`, and `Arithmetic3`, reference to whichever of `value1` or `value2` has the least difference from `target`

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
