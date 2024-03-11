# [xieite](../../xieite.md)\:\:[geometry](../../geometry.md)\:\:Point \{\}
Defined in header [<xieite/geometry/point.hpp>](../../../include/xieite/geometry/point.hpp)

&nbsp;

## Description
A structure for representing a point.

&nbsp;

## Synopsis
#### 1)
```cpp
template<xieite::concepts::Arithmetic Number = double>
struct Point {
    Number x;
    Number y;

    constexpr Point(Number = 0, Number = 0) noexcept;

    template<typename OtherNumber>
    constexpr operator xieite::geometry::Point<OtherNumber>() const noexcept;

    friend constexpr bool operator==(xieite::geometry::Point<Number>, xieite::geometry::Point<Number>) noexcept;

    constexpr std::conditional_t<std::floating_point<Number>, Number, double> angleTo(xieite::geometry::Point<Number>) const noexcept;

    constexpr std::conditional_t<std::floating_point<Number>, Number, double> distanceTo(xieite::geometry::Point<Number>) const noexcept;

    constexpr std::conditional_t<std::floating_point<Number>, Number, double> slopeTo(xieite::geometry::Point<Number>) const noexcept;

    constexpr bool contains(xieite::geometry::Point<Number>) const noexcept;

    constexpr bool contains(const xieite::geometry::Line<Number>&) const noexcept;

    constexpr bool contains(const xieite::geometry::Ray<Number>&) const noexcept;

    constexpr bool contains(const xieite::geometry::Segment<Number>& segment) const noexcept;

    constexpr bool contains(const xieite::geometry::Polygon<Number>& polygon) const noexcept;
};
```
- x
- y
- [Point](./structures/point/1/operators/constructor.md)
- [operator typename](./structures/point/1/operators/cast.md)
- [operator==](./structures/point/1/operators/equal.md)
- [angleTo](./structures/point/1/angle_to.md)
- [distanceTo](./structures/point/1/distance_to.md)
- [slopeTo](./structures/point/1/slope_to.md)
- [contains](./structures/point/1/contains.md)

&nbsp;

## Example
```cpp
#include <print>
#include "xieite/geometry/point.hpp"
#include "xieite/geometry/rotate.hpp"
#include "xieite/literals/units.hpp"

int main() {
    using namespace xieite::literals::units;

    auto point = xieite::geometry::Point(1.0, 0.0);

    point = xieite::geometry::rotate(point, 90_degrees);

    std::println("({}, {})", point.x, point.y);
}
```
Output (rounded):
```
(0, 1)
```
