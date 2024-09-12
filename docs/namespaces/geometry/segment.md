# [xieite](../../xieite.md)\:\:[geometry](../../geometry.md)\:\:Segment\<\> \{\}
Defined in fragment [xieite:geometry.Segment](../../../src/geometry/segment.cpp)

&nbsp;

## Description
A structure for representing a finite line segment.

&nbsp;

## Synopsis
#### 1)
```cpp
template<xieite::concepts::Arithmetic Arithmetic = double>
struct Segment {
    xieite::geometry::Point<Arithmetic> start;
    xieite::geometry::Point<Arithmetic> end;

    constexpr Segment(xieite::geometry::Point<Arithmetic>, xieite::geometry::Point<Arithmetic>) noexcept;

    template<typename OtherArithmetic>
    explicit(false) constexpr operator xieite::geometry::Segment<OtherArithmetic>() const noexcept;

    friend constexpr bool operator==(const xieite::geometry::Segment<Arithmetic>&, const xieite::geometry::Segment<Arithmetic>&) noexcept;

    constexpr std::conditional_t<std::floating_point<Arithmetic>, Arithmetic, double> angle() const noexcept;

    constexpr std::conditional_t<std::floating_point<Arithmetic>, Arithmetic, double> length() const noexcept;

    constexpr std::conditional_t<std::floating_point<Arithmetic>, Arithmetic, double> slope() const noexcept;

    constexpr bool contains(xieite::geometry::Point<Arithmetic>) const noexcept;

    constexpr bool contains(const xieite::geometry::Line<Arithmetic>&) const noexcept;

    constexpr bool contains(const xieite::geometry::Ray<Arithmetic>&) const noexcept;

    constexpr bool contains(const xieite::geometry::Segment<Arithmetic>&) const noexcept;

    constexpr bool contains(const xieite::geometry::Polygon<Arithmetic>&) const noexcept;
};
```
- start
- end
- [Segment\(\)](./structures/segment/1/operators/constructor.md)
- [operator typename\<\>\(\)](./structures/segment/1/operators/cast.md)
- [operator==\(\)](./structures/segment/1/operators/equal.md)
- [angle\(\)](./structures/segment/1/angle.md)
- [length\(\)](./structures/segment/1/length.md)
- [slope\(\)](./structures/segment/1/slope.md)
- [contains\(\)](./structures/segment/1/contains.md)

&nbsp;

## Example
```cpp
import std;
import xieite;

int main() {
    auto segment = xieite::geometry::Segment({ 0.0, 0.0 }, { 3.0, 4.0 });

    std::println("{}", segment.length());
}
```
Possible output:
```
5
```
