# [xieite](../../xieite.md)\:\:[math](../../math.md)\:\:closestTo\(\)
Defined in header [<xieite/math/closest_to.hpp>](../../../include/xieite/math/closest_to.hpp)

&nbsp;

## Description
Selects the value closest to a target.

&nbsp;

## Synopsis
#### 1)
```cpp
template<xieite::concepts::Arithmetic Number>
[[nodiscard]] constexpr Number& closestTo(Number target, Number& value1, Number& value2) noexcept;
```
#### 2)
```cpp
template<xieite::concepts::Arithmetic Number>
[[nodiscard]] constexpr Number closestTo(Number target, const Number& value1, const Number& value2) noexcept;
```

&nbsp;

## Example
```cpp
#include <print>
#include "xieite/math/closest_to.hpp"

int main() {
    std::println("{}", xieite::math::closestTo(0, 5, -1));
}
```
Output:
```
-1
```
