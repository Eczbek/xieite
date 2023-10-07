# [xieite](../../xieite.md)\:\:[math](../../math.md)\:\:farthestFrom
Defined in header [<xieite/math/farthestFrom.hpp>](../../../include/xieite/math/farthestFrom.hpp)

&nbsp;

## Description
Selects the value farthest from a target.

&nbsp;

## Synopses
#### 1)
```cpp
template<xieite::concepts::Numeric Number>
[[nodiscard]] constexpr Number& farthestFrom(Number target, Number& value1, Number& value2) noexcept;
```
#### 2)
```cpp
template<xieite::concepts::Numeric Number>
[[nodiscard]] constexpr const Number& farthestFrom(Number target, const Number& value1, const Number& value2) noexcept;
```

&nbsp;

## Example
```cpp
#include <iostream>
#include <xieite/math/farthestFrom.hpp>

int main() {
    std::cout << xieite::math::farthestFrom(0, 5, -1) << '\n';
}
```
Output:
```
5
```
