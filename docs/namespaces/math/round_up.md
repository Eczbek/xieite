# [xieite](../../xieite.md)\:\:[math](../../math.md)\:\:up\<\>\(\)
Defined in header [<xieite/math/up.hpp>](../../../include/xieite/math/up.hpp)

&nbsp;

## Description
Rounds a value to the nearest multiple of a step away from zero (toward either infinity).

&nbsp;

## Synopsis
#### 1)
```cpp
template<xieite::concepts::Arithmetic Arithmetic_>
[[nodiscard]] constexpr Arithmetic_ up(Arithmetic_ value, Arithmetic_ step = 1) noexcept;
```

&nbsp;

## Example
```cpp
#include <print>
#include "xieite/math/up.hpp"

int main() {
    std::println("{}", xieite::math::up(-21, 5));
}
```
Output:
```
-25
```
