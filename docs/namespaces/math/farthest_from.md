# [xieite](../../xieite.md)\:\:[math](../../math.md)\:\:farthestFrom\<\>\(\)
Defined in header [<xieite/math/farthest_from.hpp>](../../../include/xieite/math/farthest_from.hpp)

&nbsp;

## Description
Selects the value farthest from a target.

&nbsp;

## Synopsis
#### 1)
```cpp
template<xieite::concepts::Arithmetic Arithmetic>
[[nodiscard]] constexpr Arithmetic& farthestFrom(Arithmetic target, Arithmetic& value1, Arithmetic& value2) noexcept;
```
#### 2)
```cpp
template<xieite::concepts::Arithmetic Arithmetic>
[[nodiscard]] constexpr Arithmetic farthestFrom(Arithmetic target, const Arithmetic& value1, const Arithmetic& value2) noexcept;
```

&nbsp;

## Example
```cpp
#include <print>
#include "xieite/math/farthest_from.hpp"

int main() {
    std::println("{}", xieite::math::farthestFrom(0, 5, -1));
}
```
Output:
```
5
```
