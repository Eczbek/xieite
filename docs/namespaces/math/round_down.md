# [xieite](../../xieite.md)\:\:[math](../../math.md)\:\:down\<\>\(\)
Defined in header [<xieite/math/down.hpp>](../../../include/xieite/math/down.hpp)

&nbsp;

## Description
Rounds a value to the nearest multiple of a step toward zero.

&nbsp;

## Synopsis
#### 1)
```cpp
template<xieite::concepts::Arithmetic Arithmetic_>
[[nodiscard]] constexpr Arithmetic_ down(Arithmetic_ value, Arithmetic_ step = 1) noexcept;
```

&nbsp;

## Example
```cpp
#include <print>
#include "xieite/math/down.hpp"

int main() {
    std::println("{}", xieite::math::down(-24, 5));
}
```
Output:
```
-20
```
