# [xieite](../../xieite.md)\:\:[math](../../math.md)\:\:isNegative\<\>\(\)
Defined in header [<xieite/math/is_negative.hpp>](../../../include/xieite/math/is_negative.hpp)

&nbsp;

## Description
Checks that a value is negative.

&nbsp;

## Synopsis
#### 1)
```cpp
template<std::unsigned_integral UnsignedIntegral_>
[[nodiscard]] constexpr bool isNegative(UnsignedIntegral_ value) noexcept;
```
#### 2)
```cpp
template<typename Number_>
requires(std::signed_integral<Number_> || std::floating_point<Number_> || xieite::concepts::SpecializationOf<Number_, xieite::math::BigInteger>)
[[nodiscard]] constexpr bool isNegative(Number_ value) noexcept;
```

&nbsp;

## Example
```cpp
#include <print>
#include "xieite/math/is_negative.hpp"

int main() {
    std::println("{}", xieite::math::isNegative(4));
    std::println("{}", xieite::math::isNegative(-23));
}
```
Output:
```
false
true
```
