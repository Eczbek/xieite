# [xieite](../../xieite.md)\:\:[math](../../math.md)\:\:roundHalfTowardInfinity\<\>\(\)
Defined in header [<xieite/math/round_half_toward_infinity.hpp>](../../../include/xieite/math/round_half_toward_infinity.hpp)

&nbsp;

## Description
Rounds a value to the nearest multiple of a step [like so](https://en.wikipedia.org/wiki/Rounding#Rounding_half_away_from_zero).

&nbsp;

## Synopsis
#### 1)
```cpp
template<xieite::concepts::Arithmetic Arithmetic>
[[nodiscard]] constexpr Arithmetic roundHalfTowardInfinity(Arithmetic value, Arithmetic step = 1) noexcept;
```

&nbsp;

## Example
```cpp
#include <print>
#include "xieite/math/round_half_toward_infinity.hpp"

int main() {
    std::println("{}", xieite::math::roundHalfTowardInfinity(5, 10));
}
```
Output:
```
10
```
