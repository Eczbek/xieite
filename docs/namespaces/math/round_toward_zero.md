# [xieite](../../xieite.md)\:\:[math](../../math.md)\:\:roundTowardZero\<\>\(\)
Defined in header [<xieite/math/round_toward_zero.hpp>](../../../include/xieite/math/round_toward_zero.hpp)

&nbsp;

## Description
Rounds a value to the nearest multiple of a step toward zero.

&nbsp;

## Synopsis
#### 1)
```cpp
template<xieite::concepts::Arithmetic Arithmetic>
[[nodiscard]] constexpr Arithmetic roundTowardZero(Arithmetic value, Arithmetic step = 1) noexcept;
```

&nbsp;

## Example
```cpp
#include <print>
#include "xieite/math/round_toward_zero.hpp"

int main() {
    std::println("{}", xieite::math::roundTowardZero(24, 5));
}
```
Output:
```
20
```
