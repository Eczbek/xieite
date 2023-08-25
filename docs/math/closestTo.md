# [xieite](../xieite.md)\:\:[math](../math.md)\:\:closestTo
Defined in header [<xieite/math/closestTo.hpp>](../../include/xieite/math/closestTo.hpp)

&nbsp;

## Description
Selects the value closest to a target.

&nbsp;

## Synopses
#### 1)
```cpp
template<xieite::concepts::Numeric Number1, xieite::concepts::Numeric Number2, xieite::concepts::Numeric Number3>
constexpr xieite::math::Result<Number1, Number2, Number3>& closestTo(Number1 target, Number2& value1, Number3& value2) noexcept;
```
#### 2)
```cpp
template<xieite::concepts::Numeric Number1, xieite::concepts::Numeric Number2, xieite::concepts::Numeric Number3>
constexpr const xieite::math::Result<Number1, Number2, Number3>& closestTo(Number1 target, const Number2& value1, const Number3& value2) noexcept;
```

&nbsp;

## Example
```cpp
#include <iostream>
#include <xieite/math/closestTo.hpp>

int main() {
    std::cout << xieite::math::closestTo(0, 5, -1) << '\n';
}
```
Output:
```
-1
```
