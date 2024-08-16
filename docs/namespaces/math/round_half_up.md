# [xieite](../../xieite.md)\:\:[math](../../math.md)\:\:roundHalfUp\<\>\(\)
Defined in header [<xieite/math/round_half_up.hpp>](../../../include/xieite/math/round_half_up.hpp)

&nbsp;

## Description
Rounds a value to the nearest multiple of a step [like so](https://en.wikipedia.org/wiki/Rounding#Rounding_half_up).

&nbsp;

## Synopsis
#### 1)
```cpp
template<xieite::concepts::Arithmetic Arithmetic>
[[nodiscard]] constexpr Arithmetic roundHalfUp(Arithmetic value, Arithmetic step = 1) noexcept;
```

&nbsp;

## Example
```cpp
#include <print>
#include "xieite/math/round_half_up.hpp"

int main() {
    std::println("{}", xieite::math::roundHalfUp(-5, 10));
}
```
Output:
```
0
```
