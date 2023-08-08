# [xieite](../xieite.md)\:\:[math](../math.md)\:\:digits
Defined in header [<xieite/math/digits.hpp>](../../include/xieite/math/digits.hpp)

&nbsp;

## Description
Calculates the number of digits in a value of any base

&nbsp;

## Synopsis
```cpp
template<std::integral Integer>
[[nodiscard]]
constexpr std::size_t digits(const Integer value, const std::size_t base = 10) noexcept;
```
#### Template parameters
- `Integer` - An integral type satisfying `std::integral`
#### Function parameters
- `value` - - An `Integer`
- `base` - An `Integer`, set to `10` by default
#### Return type
- `std::size_t`, the number of digits

&nbsp;

## Example
```cpp
#include <iostream>
#include <xieite/math/digits.hpp>

int main() {
    std::cout
        << xieite::math::digits(12) << '\n'
        << xieite::math::digits(0b110110, 2) << '\n';
}
```
Output:
```
2
6
```
