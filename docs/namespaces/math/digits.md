# [xieite](../../xieite.md)\:\:[math](../../math.md)\:\:digits\(\)
Defined in header [<xieite/math/digits.hpp>](../../../include/xieite/math/digits.hpp)

&nbsp;

## Description
Computes the number of integral digits in a value of any radix.

&nbsp;

## Synopsis
#### 1)
```cpp
template<std::integral Integer>
[[nodiscard]] constexpr std::size_t digits(Integer value, Integer radix = 10) noexcept;
```

&nbsp;

## Example
```cpp
#include <print>
#include "xieite/math/digits.hpp"

int main() {
    std::println("{}", xieite::math::digits(12));
    std::println("{}", xieite::math::digits(0b110110, 2));
}
```
Output:
```
2
6
```
