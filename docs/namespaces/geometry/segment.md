# [xieite](../../xieite.md)\:\:[geometry](../../geometry.md)\:\:Segment\<\> \{\}
Defined in header [<xieite/geometry/segment.hpp>](../../../include/xieite/geometry/segment.hpp)

&nbsp;

## Description
A structure for representing a finite line segment.

&nbsp;

## Synopsis
#### 1)
```cpp
template<xieite::concepts::Arithmetic Arithmetic_ = double>
struct Segment {
    xieite::geometry::Point<Arithmetic_> start;
    xieite::geometry::Point<Arithmetic_> end;

    constexpr Segment(xieite::geometry::Point<Arithmetic_>, xieite::geometry::Point<Arithmetic_>) noexcept;

    template<typename OtherArithmetic_>
    constexpr operator xieite::geometry::Segment<OtherArithmetic_>() const noexcept;

    friend constexpr bool operator==(const xieite::geometry::Segment<Arithmetic_>&, const xieite::geometry::Segment<Arithmetic_>&) noexcept;

    constexpr std::conditional_t<std::floating_point<Arithmetic_>, Arithmetic_, double> angle() const noexcept;

    constexpr std::conditional_t<std::floating_point<Arithmetic_>, Arithmetic_, double> length() const noexcept;

    constexpr std::conditional_t<std::floating_point<Arithmetic_>, Arithmetic_, double> slope() const noexcept;

    constexpr bool contains(xieite::geometry::Point<Arithmetic_>) const noexcept;

    constexpr bool contains(const xieite::geometry::Line<Arithmetic_>&) const noexcept;

    constexpr bool contains(const xieite::geometry::Ray<Arithmetic_>&) const noexcept;

    constexpr bool contains(const xieite::geometry::Segment<Arithmetic_>&) const noexcept;

    constexpr bool contains(const xieite::geometry::Polygon<Arithmetic_>&) const noexcept;
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
