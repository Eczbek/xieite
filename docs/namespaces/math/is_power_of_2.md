# [xieite](../../xieite.md)\:\:[math](../../math.md)\:\:isPowerOf2\<\>\(\)
Defined in header [<xieite/math/is_power_of_2.hpp>](../../../include/xieite/math/is_power_of_2.hpp)

&nbsp;

## Description
Checks that a value is a power of 2.

&nbsp;

## Synopsis
#### 1)
```cpp
template<std::unsigned_integral UnsignedIntegral_>
[[nodiscard]] constexpr bool isPowerOf2(UnsignedIntegral_ value) noexcept;
```

&nbsp;

## Example
```cpp
#include <print>
#include "xieite/math/is_power_of_2.hpp"

int main() {
    std::println("{}", xieite::math::isPowerOf2<unsigned int>(4));
    std::println("{}", xieite::math::isPowerOf2<unsigned int>(0));
}
```
Output:
```
true
false
```
