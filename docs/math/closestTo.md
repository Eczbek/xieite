# [xieite](../xieite.md)\:\:[math](../math.md)\:\:closestTo
Defined in header [<xieite/math/closestTo.hpp>](../../include/xieite/math/closestTo.hpp)

&nbsp;

## Description
Selects the value closest to a target.

&nbsp;

## Synopses
#### 1)
```cpp
template<xieite::concepts::Numeric Number>
constexpr Number& closestTo(Number target, Number& value1, Number& value2) noexcept;
```
#### 2)
```cpp
template<xieite::concepts::Numeric Number>
constexpr const Number& closestTo(Number target, const Number& value1, const Number& value2) noexcept;
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
