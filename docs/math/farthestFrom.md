# [xieite](../xieite.md)\:\:[math](../math.md)\:\:farthestFrom
Defined in header [<xieite/math/farthestFrom.hpp>](../../include/xieite/math/farthestFrom.hpp)

&nbsp;

## Description
Selects the value farthest from a target

&nbsp;

## Synopses

&nbsp;

```cpp
template<xieite::concepts::Arithmetic Arithmetic1, xieite::concepts::Arithmetic Arithmetic2, xieite::concepts::Arithmetic Arithmetic3>
[[nodiscard]]
constexpr xieite::math::Result<Arithmetic1, Arithmetic2, Arithmetic3>& farthestFrom(const Arithmetic1 target, Arithmetic2& value1, Arithmetic3& value2) noexcept;
```
#### Template parameters
- `Arithmetic1` - A type satisfying `xieite::concepts::Arithmetic`
- `Arithmetic2` - A type satisfying `xieite::concepts::Arithmetic`
- `Arithmetic3` - A type satisfying `xieite::concepts::Arithmetic`
#### Function parameters
- `target` - An `Arithmetic1`
- `value1` - An `Arithmetic2` reference
- `value2` - An `Arithmetic3` reference
#### Return type
- `xieite::math::Result` of `Arithmetic1`, `Arithmetic2`, and `Arithmetic3`, reference to whichever of `value1` and `value2` has the greatest difference from target

&nbsp;

```cpp
template<xieite::concepts::Arithmetic Arithmetic1, xieite::concepts::Arithmetic Arithmetic2, xieite::concepts::Arithmetic3>
[[nodiscard]]
constexpr const xieite::math::Result<Arithmetic1, Arithmetic2, Arithmetic3>& farthestFrom(const Arithmetic1 target, const Arithmetic2& value1, const Arithmetic3& value2) noexcept;
```
#### Template parameters
- `Arithmetic1` - A type satisfying `xieite::concepts::Arithmetic`
- `Arithmetic2` - A type satisfying `xieite::concepts::Arithmetic`
- `Arithmetic3` - A type satisfying `xieite::concepts::Arithmetic`
#### Function parameters
- `target` - An `Arithmetic1`
- `value1` - An `Arithmetic2` constant reference
- `value2` - Also a `Arithmetic3` constant reference
#### Return type
- `xieite::math::Result` of `Arithmetic1`, `Arithmetic2`, and `Arithmetic3`, constant reference to whichever of `value1` and `value2` has the greatest difference from target

&nbsp;

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
