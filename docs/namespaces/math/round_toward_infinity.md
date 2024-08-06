# [xieite](../../xieite.md)\:\:[math](../../math.md)\:\:roundTowardInfinity\<\>\(\)
Defined in header [<xieite/math/round_toward_infinity.hpp>](../../../include/xieite/math/round_toward_infinity.hpp)

&nbsp;

## Description
Rounds a value to the nearest multiple of a step toward infinity.

&nbsp;

## Synopsis
#### 1)
```cpp
template<xieite::concepts::Arithmetic Arithmetic_>
[[nodiscard]] constexpr Arithmetic_ roundTowardInfinity(Arithmetic_ value, Arithmetic_ step = 1) noexcept;
```

&nbsp;

## Example
```cpp
#include <print>
#include "xieite/math/round_toward_infinity.hpp"

int main() {
    std::println("{}", xieite::math::roundTowardInfinity(21, 5));
}
```
Output:
```
25
```
