# [xieite](../../xieite.md)\:\:[geometry](../../geometry.md)\:\:rotate
Defined in header [<xieite/geometry/rotate.hpp"](../../../include/xieite/geometry/rotate.hpp)

&nbsp;

## Description
Rotates shapes a specific angle around any pivot, clockwise.

&nbsp;

## Synopses
#### 1)
```cpp
[[nodiscard]] constexpr xieite::geometry::Point rotate(xieite::geometry::Point point, double angle, xieite::geometry::Point pivot = xieite::geometry::Point(0, 0)) noexcept;
```
#### 2)
```cpp
template<xieite::concepts::LinearShape LinearShape>
[[nodiscard]] constexpr LinearShape rotate(const LinearShape& linearShape, double angle, xieite::geometry::Point pivot = xieite::geometry::Point(0, 0)) noexcept;
```
#### 3)
```cpp
[[nodiscard]] constexpr xieite::geometry::Polygon rotate(xieite::geometry::Polygon polygon, double angle, xieite::geometry::Point pivot = xieite::geometry::Point(0, 0)) noexcept;
```

&nbsp;

## Example
```cpp
#include <iostream>
#include "xieite/geometry/line.hpp"
#include "xieite/geometry/rotate.hpp"
#include "xieite/units/literals/angles.hpp"

int main() {
    using namespace xieite::units::literals;

    xieite::geometry::Line line1({ 0.0, 0.0 }, { 1.0, 1.0 });

    xieite::geometry::Line line2 = xieite::geometry::rotate(line1, 90_degrees);

    std::cout
        << line1.slope() << '\n'
        << line2.slope() << '\n';
}
```
Output:
```
1
-1
```
