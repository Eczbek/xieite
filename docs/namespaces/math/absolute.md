# [xieite](../../xieite.md)\:\:[math](../../math.md)\:\:absolute\<\>\(\)
Defined in header [<xieite/math/absolute.hpp>](../../../include/xieite/math/absolute.hpp)

&nbsp;

## Description
Returns the unsigned absolute of a value.

&nbsp;

## Synopsis
#### 1)
```cpp
template<std::integral Integral_>
[[nodiscard]] constexpr xieite::types::TryUnsigned<Integral_> absolute(Integral_ value) noexcept;
```
#### 2)
```cpp
template<std::floating_point Fractional_>
[[nodiscard]] constexpr Fractional_ absolute(Fractional_ value) noexcept;
```

&nbsp;

## Example
```cpp
#include <cstdint>
#include <limits>
#include <print>
#include "xieite/math/absolute.hpp"

int main() {
    std::int64_t value = std::numeric_limits<std::int64_t>::min();

    std::println("{}", value);
    std::println("{}", xieite::math::absolute(value));
}
```
Output:
```
-9223372036854775808
9223372036854775808
```
