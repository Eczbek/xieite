# [xieite](../../xieite.md)\:\:[math](../../math.md)\:\:farthestFrom\<\>\(\)
Defined in header [<xieite/math/farthest_from.hpp>](../../../include/xieite/math/farthest_from.hpp)

&nbsp;

## Description
Selects the value farthest from a target.

&nbsp;

## Synopsis
#### 1)
```cpp
template<xieite::concepts::Arithmetic Arithmetic_>
[[nodiscard]] constexpr Arithmetic_& farthestFrom(Arithmetic_ target, Arithmetic_& value1, Arithmetic_& value2) noexcept;
```
#### 2)
```cpp
template<xieite::concepts::Arithmetic Arithmetic_>
[[nodiscard]] constexpr Arithmetic_ farthestFrom(Arithmetic_ target, const Arithmetic_& value1, const Arithmetic_& value2) noexcept;
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
