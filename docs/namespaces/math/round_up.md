# [xieite](../../xieite.md)\:\:[math](../../math.md)\:\:roundUp\(\)
Defined in header [<xieite/math/round_up.hpp>](../../../include/xieite/math/round_up.hpp)

&nbsp;

## Description
Rounds a value to the nearest multiple of a step away from zero.

&nbsp;

## Synopsis
#### 1)
```cpp
template<xieite::concepts::Arithmetic Number>
[[nodiscard]] constexpr Number roundUp(Number value, Number step = 1) noexcept;
```

&nbsp;

## Example
```cpp
#include <print>
#include "xieite/math/round_up.hpp"

int main() {
    std::println("{}", xieite::math::roundUp(-21, 5));
}
```
Output:
```
-25
```
