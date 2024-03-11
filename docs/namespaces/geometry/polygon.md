# [xieite](../../xieite.md)\:\:[geometry](../../geometry.md)\:\:Polygon \{\}
Defined in header [<xieite/geometry/polygon.hpp>](../../../include/xieite/geometry/polygon.hpp)

&nbsp;

## Description
A structure for representing a polygon.

&nbsp;

## Synopsis
#### 1)
```cpp
template<xieite::concepts::Arithmetic Number = double>
struct Polygon {
    std::vector<xieite::geometry::Point<Number>> points;

    template<xieite::concepts::RangeOf<xieite::geometry::Point<Number>> Range = std::vector<xieite::geometry::Point<Number>>>
    constexpr Polygon(Range&&) noexcept;

    template<typename OtherNumber>
    constexpr operator xieite::geometry::Polygon<OtherNumber>() const noexcept;

    friend constexpr bool operator==(const xieite::geometry::Polygon<Number>&, const xieite::geometry::Polygon<Number>&) noexcept;

    static constexpr xieite::geometry::Polygon<Number> rectangle(xieite::geometry::Point<Number>, xieite::geometry::Point<Number>) noexcept;

    constexpr double area() const noexcept;

    constexpr double perimeter() const noexcept;

    constexpr std::vector<xieite::geometry::Segment<Number>> sides() const noexcept;

    constexpr bool contains(xieite::geometry::Point<Number>) const noexcept;

    constexpr bool contains(const xieite::geometry::Line<Number>&) const noexcept;

    constexpr bool contains(const xieite::geometry::Ray<Number>&) const noexcept;

    constexpr bool contains(const xieite::geometry::Segment<Number>&) const noexcept;

    constexpr bool contains(const xieite::geometry::Polygon<Number>&) const noexcept;
};
```
- points
- [Polygon](./structures/polygon/1/operators/constructor.md)
- [operator typename](./structures/polygon/1/operators/cast.md)
- [operator==](./structures/polygon/1/operators/equal.md)
- [rectangle](./structures/polygon/1/rectangle.md)
- [area](./structures/polygon/1/area.md)
- [perimeter](./structures/polygon/1/perimeter.md)
- [sides](./structures/polygon/1/sides.md)
- [contains](./structures/polygon/1/contains.md)

&nbsp;

## Example
```cpp
#include <print>
#include "xieite/geometry/polygon.hpp"

int main() {
    auto polygon = xieite::geometry::Polygon({
        { 1.0, 0.0 },
        { 2.0, 1.0 },
        { 1.0, 2.0 },
        { 0.0, 1.0 }
    });

    std::println("{}", polygon.area());
}
```
Possible output:
```
2
```
