# [xieite](../../xieite.md)\:\:[math](../../math.md)\:\:multiply\<\>\(\)
Defined in fragment [xieite:math.multiply](../../../src/math/multiply.cpp)

&nbsp;

## Description
Computes the product of two unsigned integers in two parts. Intended for avoiding the usage of a larger integer type to store the result.

&nbsp;

## Synopsis
#### 1)
```cpp
template<std::unsigned_integral UnsignedIntegral>
[[nodiscard]] constexpr xieite::math::Product<UnsignedIntegral> multiply(UnsignedIntegral multiplier, std::common_type_t<UnsignedIntegral> multiplicand) noexcept;
```

&nbsp;

## Example
```cpp
import std;
import xieite;

int main() {
    std::uint8_t x = 255;
    std::uint8_t y = 255;
    xieite::math::Product<std::uint8_t> z = xieite::math::multiply(x, y);
    std::println("{}", ((static_cast<std::uint16_t>(z.upper) << 8) | z.lower));
}
```
Output:
```
65025
```
