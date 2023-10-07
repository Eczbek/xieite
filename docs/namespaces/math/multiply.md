# [xieite](../../xieite.md)\:\:[math](../../math.md)\:\:multiply
Defined in header [<xieite/math/multiply.hpp>](../../../include/xieite/math/multiply.hpp)

&nbsp;

## Description
Computes the product of two unsigned integers in two parts. Intended for avoiding the usage of a larger integer type to store the result.

&nbsp;

## Synopses
#### 1)
```cpp
template<std::unsigned_integral UnsignedInteger>
[[nodiscard]] constexpr xieite::math::Product<UnsignedInteger> multiply(const UnsignedInteger multiplier, const UnsignedInteger multiplicand) noexcept;
```

&nbsp;

## Example
```cpp
#include <iostream>
#include <xieite/math/Product.hpp>
#include <xieite/math/multiply.hpp>

int main() {
    std::uint8_t x = 255;
    std::uint8_t y = 255;
    xieite::math::Product<std::uint8_t> z = xieite::math::multiply(x, y);
    std::cout << ((static_cast<std::uint16_t>(z.upper) << 8) | z.lower) << '\n';
}
```
Output:
```
65025
```
