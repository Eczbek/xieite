# [xieite](../xieite.md)\:\:[math](../math.md)\:\:difference
Defined in header [<xieite/math/difference.hpp>](../../include/xieite/math/difference.hpp)

&nbsp;

## Description
Calculates the absolute difference between two values. Handles some edge cases

&nbsp;

## Synopses

&nbsp;

```cpp
template<std::integral Integer>
[[nodiscard]]
constexpr std::make_unsigned<Integer> difference(Integer a, Integer b) noexcept;
```
#### Template parameters
- `Integer` - An integral type satisfying `std::integral`
#### Function parameters
- `a` - An `Integer`
- `b` - Another `Integer`
#### Return type
- `std::make_unsigned` of `Integer`, the absolute difference between `a` and `b`

&nbsp;

```cpp
template<std::floating_point Floating>
[[nodiscard]]
constexpr Floating difference(Floating a, Floating b) noexcept;
```
#### Template parameters
- `Floating` - A floating point type satisfying `std::floating_point`
#### Function parameters
- `a` - A `Floating`
- `b` - Also a `Floating`
#### Return type
- `Floating`, the absolute difference between `a` and `b`

&nbsp;

## Example
```cpp
#include <cstdint>
#include <iostream>
#include <limits>
#include <xieite/math/difference.hpp>

int main() {
    std::int8_t min = std::numeric_limits<std::int8_t>::min();
    std::int8_t max = std::numeric_limits<std::int8_t>::max();

    std::cout
        << min << '\n'
        << max << '\n'
        << xieite::math::difference(min, max) << '\n';
}
```
Output:
```
-128
127
255
```
