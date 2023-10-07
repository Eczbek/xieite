# [xieite](../../xieite.md)\:\:[math](../../math.md)\:\:digits
Defined in header [<xieite/math/digits.hpp>](../../../include/xieite/math/digits.hpp)

&nbsp;

## Description
Computes the number of digits in a value of any base.

&nbsp;

## Synopses
#### 1)
```cpp
template<std::integral Integer>
[[nodiscard]] constexpr std::size_t digits(Integer value, std::size_t base = 10) noexcept;
```

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
