# [xieite](../../xieite.md)\:\:[math](../../math.md)\:\:power\(\)
Defined in header [<xieite/math/power.hpp>](../../../include/xieite/math/power.hpp)

&nbsp;

## Description
Computes a power of an integer.

&nbsp;

## Synopsis
#### 1)
```cpp
template<std::integral Integral>
[[nodiscard]] constexpr Integral power(Integral base, std::size_t exponent) noexcept;
```

&nbsp;

## Example
```cpp
#include <print>
#include "xieite/math/power.hpp"

int main() {
    std::println("{}", xieite::math::power<std::uint64_t>(4, 13));
}
```
Output:
```
67108864
```
