# [xieite](../../xieite.md)\:\:[math](../../math.md)\:\:roundDown\<\>\(\)
Defined in header [<xieite/math/round_down.hpp>](../../../include/xieite/math/round_down.hpp)

&nbsp;

## Description
Rounds a value to the nearest multiple of a step downwards.

&nbsp;

## Synopsis
#### 1)
```cpp
template<xieite::concepts::Arithmetic Arithmetic_>
[[nodiscard]] constexpr Arithmetic_ roundDown(Arithmetic_ value, Arithmetic_ step = 1) noexcept;
```

&nbsp;

## Example
```cpp
#include <print>
#include "xieite/math/round_down.hpp"

int main() {
    std::println("{}", xieite::math::roundDown(-21, 5));
}
```
Output:
```
-25
```
