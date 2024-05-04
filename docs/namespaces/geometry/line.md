# [xieite](../../xieite.md)\:\:[geometry](../../geometry.md)\:\:Line\<\> \{\}
Defined in header [<xieite/geometry/line.hpp>](../../../include/xieite/geometry/line.hpp)

&nbsp;

## Description
An structure for representing an infinite line.

&nbsp;

## Synopsis
#### 1)
```cpp
template<xieite::concepts::Arithmetic Arithmetic_ = double>
struct Line {
    xieite::geometry::Point<Arithmetic_> start;
    xieite::geometry::Point<Arithmetic_> end;

    constexpr Line(xieite::geometry::Point<Arithmetic_>, xieite::geometry::Point<Arithmetic_>) noexcept;

    constexpr Line(xieite::geometry::Point<Arithmetic_>, std::conditional_t<std::floating_point<Arithmetic_>, Arithmetic_, double>) noexcept;

    template<typename OtherArithmetic_>
    constexpr operator xieite::geometry::Line<OtherArithmetic_>() const noexcept;

    friend constexpr bool operator==(const xieite::geometry::Line<Arithmetic_>&, const xieite::geometry::Line<Arithmetic_>&) noexcept;

    constexpr std::conditional_t<std::floating_point<Arithmetic_>, Arithmetic_, double> angle() const noexcept;

    constexpr std::conditional_t<std::floating_point<Arithmetic_>, Arithmetic_, double> length() const noexcept;

    constexpr std::conditional_t<std::floating_point<Arithmetic_>, Arithmetic_, double> slope() const noexcept;

    constexpr bool contains(xieite::geometry::Point<Arithmetic_>) const noexcept;

    constexpr bool contains(xieite::geometry::Line<Arithmetic_>&) const noexcept;

    constexpr bool contains(xieite::geometry::Ray<Arithmetic_>&) const noexcept;

    constexpr bool contains(xieite::geometry::Segment<Arithmetic_>&) const noexcept;

    constexpr bool contains(xieite::geometry::Polygon<Arithmetic_>&) const noexcept;
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
    auto line = xieite::geometry::Line({ 0.0, 0.0 }, { 1.0, 1.0 });

    std::println("{}", line.angle());
}
```
Output:
```
0.7853981633974483
```
