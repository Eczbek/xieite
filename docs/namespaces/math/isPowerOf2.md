# [xieite](../../xieite.md)\:\:[math](../../math.md)\:\:isPowerOf2
Defined in header [<xieite/math/isPowerOf2.hpp>](../../../include/xieite/math/isPowerOf2.hpp)

&nbsp;

## Description
Checks that a value is a power of 2.

&nbsp;

## Synopses
#### 1)
```cpp
template<std::unsigned_integral UnsignedInteger>
[[nodiscard]] constexpr bool isPowerOf2(UnsignedInteger value) noexcept;
```

&nbsp;

## Example
```cpp
#include <iostream>
#include <xieite/math/isPowerOf2.hpp>

int main() {
    std::cout
        << std::boolalpha
        << xieite::math::isPowerOf2(4) << '\n'
        << xieite::math::isPowerOf2(0) << '\n';
}
```
Output:
```
true
false
```
