# [xieite](../../xieite.md)\:\:[math](../../math.md)\:\:absolute\(\)
Defined in header [<xieite/math/absolute.hpp>](../../../include/xieite/math/absolute.hpp)

&nbsp;

## Description
Returns the unsigned absolute of a value.

&nbsp;

## Synopsis
#### 1)
```cpp
template<std::integral Integer>
[[nodiscard]] constexpr xieite::types::MaybeUnsigned<Integer> absolute(Integer value) noexcept;
```
#### 2)
```cpp
template<std::floating_point FloatingPoint>
[[nodiscard]] constexpr FloatingPoint absolute(FloatingPoint value) noexcept;
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
