# [xieite](../../xieite.md)\:\:[geometry](../../geometry.md)\:\:Segment \{\}
Defined in header [<xieite/geometry/segment.hpp>](../../../include/xieite/geometry/segment.hpp)

&nbsp;

## Description
A structure for representing a finite line segment.

&nbsp;

## Synopsis
#### 1)
```cpp
template<xieite::concepts::Arithmetic Number = double>
struct Segment {
    xieite::geometry::Point<Number> start;
    xieite::geometry::Point<Number> end;

    constexpr Segment(xieite::geometry::Point<Number>, xieite::geometry::Point<Number>) noexcept;

    template<typename OtherNumber>
    constexpr operator xieite::geometry::Segment<OtherNumber>() const noexcept;

    friend constexpr bool operator==(const xieite::geometry::Segment<Number>&, const xieite::geometry::Segment<Number>&) noexcept;

    constexpr std::conditional_t<std::floating_point<Number>, Number, double> angle() const noexcept;

    constexpr std::conditional_t<std::floating_point<Number>, Number, double> length() const noexcept;

    constexpr std::conditional_t<std::floating_point<Number>, Number, double> slope() const noexcept;

    constexpr bool contains(xieite::geometry::Point<Number>) const noexcept;

    constexpr bool contains(const xieite::geometry::Line<Number>&) const noexcept;

    constexpr bool contains(const xieite::geometry::Ray<Number>&) const noexcept;

    constexpr bool contains(const xieite::geometry::Segment<Number>&) const noexcept;

    constexpr bool contains(const xieite::geometry::Polygon<Number>&) const noexcept;
};
```
- start
- end
- [Segment](./structures/segment/1/operators/constructor.md)
- [operator typename](./structures/segment/1/operators/cast.md)
- [operator==](./structures/segment/1/operators/equal.md)
- [angle](./structures/segment/1/angle.md)
- [length](./structures/segment/1/length.md)
- [slope](./structures/segment/1/slope.md)
- [contains](./structures/segment/1/contains.md)

&nbsp;

## Example
```cpp
#include <print>
#include "xieite/geometry/segment.hpp"

int main() {
    auto segment = xieite::geometry::Segment({ 0.0, 0.0 }, { 3.0, 4.0 });

    std::println("{}", segment.length());
}
```
Possible output:
```
5
```
