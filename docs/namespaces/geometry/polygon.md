# [xieite](../../xieite.md)\:\:[geometry](../../geometry.md)\:\:Polygon\<\> \{\}
Defined in header [<xieite/geometry/polygon.hpp>](../../../include/xieite/geometry/polygon.hpp)

&nbsp;

## Description
A structure for representing a polygon.

&nbsp;

## Synopsis
#### 1)
```cpp
template<xieite::concepts::Arithmetic Arithmetic_ = double>
struct Polygon {
    std::vector<xieite::geometry::Point<Arithmetic_>> points;

    template<xieite::concepts::RangeOf<xieite::geometry::Point<Arithmetic_>> Range_ = std::vector<xieite::geometry::Point<Arithmetic_>>>
    constexpr Polygon(Range_&&) noexcept;

    template<typename OtherArithmetic_>
    constexpr operator xieite::geometry::Polygon<OtherArithmetic_>() const noexcept;

    friend constexpr bool operator==(const xieite::geometry::Polygon<Arithmetic_>&, const xieite::geometry::Polygon<Arithmetic_>&) noexcept;

    static constexpr xieite::geometry::Polygon<Arithmetic_> rectangle(xieite::geometry::Point<Arithmetic_>, xieite::geometry::Point<Arithmetic_>) noexcept;

    constexpr double area() const noexcept;

    constexpr double perimeter() const noexcept;

    constexpr std::vector<xieite::geometry::Segment<Arithmetic_>> sides() const noexcept;

    constexpr bool contains(xieite::geometry::Point<Arithmetic_>) const noexcept;

    constexpr bool contains(const xieite::geometry::Line<Arithmetic_>&) const noexcept;

    constexpr bool contains(const xieite::geometry::Ray<Arithmetic_>&) const noexcept;

    constexpr bool contains(const xieite::geometry::Segment<Arithmetic_>&) const noexcept;

    constexpr bool contains(const xieite::geometry::Polygon<Arithmetic_>&) const noexcept;
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
