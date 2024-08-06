# [xieite](../../xieite.md)\:\:[math](../../math.md)\:\:roundHalfDown\<\>\(\)
Defined in header [<xieite/math/round_half_down.hpp>](../../../include/xieite/math/round_half_down.hpp)

&nbsp;

## Description
Rounds a value to the nearest multiple of a step [like so](https://en.wikipedia.org/wiki/Rounding#Rounding_half_down).

&nbsp;

## Synopsis
#### 1)
```cpp
template<xieite::concepts::Arithmetic Arithmetic_>
[[nodiscard]] constexpr Arithmetic_ roundHalfDown(Arithmetic_ value, Arithmetic_ step = 1) noexcept;
```

&nbsp;

## Example
```cpp
#include <print>
#include "xieite/math/round_half_down.hpp"

int main() {
    std::println("{}", xieite::math::roundHalfDown(-5, 10));
}
```
Output:
```
-10
```
