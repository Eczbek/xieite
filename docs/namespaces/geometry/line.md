# [xieite](../../xieite.md)\:\:[geometry](../../geometry.md)\:\:Line \{\}
Defined in header [<xieite/geometry/line.hpp>](../../../include/xieite/geometry/line.hpp)

&nbsp;

## Description
An structure for representing an infinite line.

&nbsp;

## Synopsis
#### 1)
```cpp
template<xieite::concepts::Arithmetic Number = double>
struct Line {
    xieite::geometry::Point<Number> start;
    xieite::geometry::Point<Number> end;

    constexpr Line(xieite::geometry::Point<Number>, xieite::geometry::Point<Number>) noexcept;

    constexpr Line(xieite::geometry::Point<Number>, std::conditional_t<std::floating_point<Number>, Number, double>) noexcept;

    template<typename OtherNumber>
    constexpr operator xieite::geometry::Line<OtherNumber>() const noexcept;

    friend constexpr bool operator==(const xieite::geometry::Line<Number>&, const xieite::geometry::Line<Number>&) noexcept;

    constexpr std::conditional_t<std::floating_point<Number>, Number, double> angle() const noexcept;

    constexpr std::conditional_t<std::floating_point<Number>, Number, double> length() const noexcept;

    constexpr std::conditional_t<std::floating_point<Number>, Number, double> slope() const noexcept;

    constexpr bool contains(xieite::geometry::Point<Number>) const noexcept;

    constexpr bool contains(xieite::geometry::Line<Number>&) const noexcept;

    constexpr bool contains(xieite::geometry::Ray<Number>&) const noexcept;

    constexpr bool contains(xieite::geometry::Segment<Number>&) const noexcept;

    constexpr bool contains(xieite::geometry::Polygon<Number>&) const noexcept;
};
```
- start
- end
- [Line](./structures/line/1/operators/constructor.md)
- [operator typename](./structures/line/1/operators/cast.md)
- [operator==](./structures/line/1/operators/equal.md)
- [angle](./structures/line/1/angle.md)
- [length](./structures/line/1/length.md)
- [slope](./structures/line/1/slope.md)
- [contains](./structures/line/1/contains.md)

&nbsp;

## Example
```cpp
#include <print>
#include "xieite/geometry/line.hpp"

int main() {
    auto line1 = xieite::geometry::Line({ 0.0, 0.0 }, { 1.0, 1.0 });

    std::println("{}", line.angle());
}
```
Output:
```