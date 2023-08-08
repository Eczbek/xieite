# [xieite](../xieite.md)\:\:[math](../math.md)\:\:absolute
Defined in header [<xieite/math/absolute.hpp>](../../include/xieite/math/absolute.hpp)

&nbsp;

## Description
Returns the absolute of a value

&nbsp;

## Synopses

&nbsp;

```cpp
template<std::integral Integer>
[[nodiscard]]
constexpr std::make_unsigned_t<Integer> absolute(Integer value) noexcept;
```
#### Template parameters
- `Integer` - Any integral type satisfying `std::integral`
#### Function parameters
- `value` - An `Integer`
#### Return type
- `std::make_unsigned_t` of `Integer`, the absolute of `value`

&nbsp;

```cpp
template<std::floating_point Floating>
[[nodiscard]]
constexpr Floating absolute(const Floating value) noexcept;
```
#### Template parameters
- `Floating` - A floating point type satisfying `std::floating_point`
#### Function parameters
- `value` - A `Floating`
#### Return type
- `Floating`, the absolute of `value`

&nbsp;

## Example
```cpp
#include <cstdint>
#include <iostream>
#include <xieite/math/absolute.hpp>

int main() {
    std::int16_t value = -32768;
    
    std::cout << xieite::math::absolute(value) << '\n';
}
```
Output:
```
32768
```
