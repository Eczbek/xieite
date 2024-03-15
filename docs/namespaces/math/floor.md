# [xieite](../../xieite.md)\:\:[math](../../math.md)\:\:floor\(\)
Defined in header [<xieite/math/floor.hpp>](../../../include/xieite/math/floor.hpp)

&nbsp;

## Description
Rounds a value down to the previous multiple of a step.

&nbsp;

## Synopsis
#### 1)
```cpp
template<xieite::concepts::Arithmetic Number>
[[nodiscard]] constexpr Number floor(Number value, Number step = 1) noexcept;
```

&nbsp;

## Example
```cpp
#include <print>
#include "xieite/math/floor.hpp"

int main() {
    std::println("{}", xieite::math::floor(17, 6));
}
```
Output:
```
12
```
