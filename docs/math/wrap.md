# [xieite](../xieite.md)\:\:[math](../math.md)\:\:wrap
Defined in header [<xieite/math/wrap.hpp>](../../include/xieite/math/wrap.hpp)

&nbsp;

## Description
"Wraps" a number between two limits, inclusively

&nbsp;

## Synopsis
```cpp
template<xieite::concepts::Arithmetic Arithmetic1, xieite::concepts::Arithmetic Arithmetic2, xieite::concepts::Arithmetic Arithmetic3>
[[nodiscard]]
constexpr std::common_type_t<Arithmetic1, Arithmetic2, Arithmetic3> wrap(const Arithmetic1 value, const Arithmetic2 limit1, const Arithmetic3 limit2) noexcept;
```
#### Template parameters
- `Arithmetic1` - A type satisfying `xieite::concepts::Arithmetic`
- `Arithmetic2` - A type satisfying `xieite::concepts::Arithmetic`
- `Arithmetic3` - A type satisfying `xieite::concepts::Arithmetic`
#### Function parameters
- `value` - An `Arithmetic1`, the value to wrap
- `limit1` - An `Arithmetic2`, one inclusive limit
- `limit2` - An `Arithmetic3`, other inclusive limit
#### Return type
- `std::common_type_t` of `Arithmetic1`, `Arithmetic2`, and `Arithmetic3`

&nbsp;

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
