# [xieite](../../../../../xieite.md)\:\:[geometry](../../../../../geometry.md)\:\:[Polygon](../../../polygon.md)\:\:perimeter
Defined in header [<xieite/geometry/polygon.hpp>](../../../../../../include/xieite/geometry/polygon.hpp)

&nbsp;

## Description
Computes the perimeter of this polygon.

&nbsp;

## Synopses
#### 1)
```cpp
[[nodiscard]] constexpr double perimeter() const noexcept;
```

&nbsp;

## Example
```cpp
#include <iostream>
#include <xieite/geometry/point.hpp>
#include <xieite/geometry/polygon.hpp>

int main() {
    std::cout << xieite::geometry::Polygon({
        { 0, 0 },
        { 2, 0 },
        { 2, 2 },
        { 0, 2 }
    }).perimeter() << '\n';
}
```
Output:
```
8
```
