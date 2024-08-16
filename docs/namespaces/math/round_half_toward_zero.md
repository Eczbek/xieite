# [xieite](../../xieite.md)\:\:[math](../../math.md)\:\:roundHalfTowardZero\<\>\(\)
Defined in header [<xieite/math/round_half_toward_zero.hpp>](../../../include/xieite/math/round_half_toward_zero.hpp)

&nbsp;

## Description
Rounds a value to the nearest multiple of a step [like so](https://en.wikipedia.org/wiki/Rounding#Rounding_half_toward_zero).

&nbsp;

## Synopsis
#### 1)
```cpp
template<xieite::concepts::Arithmetic Arithmetic>
[[nodiscard]] constexpr Arithmetic roundHalfTowardZero(Arithmetic value, Arithmetic step = 1) noexcept;
```

&nbsp;

## Example
```cpp
#include <print>
#include "xieite/math/round_half_toward_zero.hpp"

int main() {
    std::println("{}", xieite::math::roundHalfTowardZero(5, 10));
}
```
Output:
```
0
```
