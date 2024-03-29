# [xieite](../../xieite.md)\:\:[math](../../math.md)\:\:farthestFrom\(\)
Defined in header [<xieite/math/farthest_from.hpp>](../../../include/xieite/math/farthest_from.hpp)

&nbsp;

## Description
Selects the value farthest from a target.

&nbsp;

## Synopsis
#### 1)
```cpp
template<xieite::concepts::Arithmetic Number>
[[nodiscard]] constexpr Number& farthestFrom(Number target, Number& value1, Number& value2) noexcept;
```
#### 2)
```cpp
template<xieite::concepts::Arithmetic Number>
[[nodiscard]] constexpr Number farthestFrom(Number target, const Number& value1, const Number& value2) noexcept;
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
