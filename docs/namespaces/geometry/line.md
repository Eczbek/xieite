# [xieite](../../xieite.md)\:\:[geometry](../../geometry.md)\:\:Line\<\> \{\}
Defined in fragment [xieite:geometry.Line](../../../src/geometry/line.cpp)

&nbsp;

## Description
An structure for representing an infinite line.

&nbsp;

## Synopsis
#### 1)
```cpp
template<xieite::concepts::Arithmetic Arithmetic = double>
struct Line {
    xieite::geometry::Point<Arithmetic> start;
    xieite::geometry::Point<Arithmetic> end;

    constexpr Line(xieite::geometry::Point<Arithmetic>, xieite::geometry::Point<Arithmetic>) noexcept;

    constexpr Line(xieite::geometry::Point<Arithmetic>, std::conditional_t<std::floating_point<Arithmetic>, Arithmetic, double>) noexcept;

    template<typename OtherArithmetic>
    explicit(false) constexpr operator Line<OtherArithmetic>() const noexcept;

    friend constexpr bool operator==(const Line&, const Line&) noexcept;

    constexpr std::conditional_t<std::floating_point<Arithmetic>, Arithmetic, double> angle() const noexcept;

    constexpr std::conditional_t<std::floating_point<Arithmetic>, Arithmetic, double> length() const noexcept;

    constexpr std::conditional_t<std::floating_point<Arithmetic>, Arithmetic, double> slope() const noexcept;

    constexpr bool contains(xieite::geometry::Point<Arithmetic>) const noexcept;

    constexpr bool contains(Line&) const noexcept;

    constexpr bool contains(xieite::geometry::Ray<Arithmetic>&) const noexcept;

    constexpr bool contains(xieite::geometry::Segment<Arithmetic>&) const noexcept;

    constexpr bool contains(xieite::geometry::Polygon<Arithmetic>&) const noexcept;
};
```
- start
- end
- [Line\(\)](./structures/line/1/operators/constructor.md)
- [operator typename\<\>\(\)](./structures/line/1/operators/cast.md)
- [operator==\(\)](./structures/line/1/operators/equal.md)
- [angle\(\)](./structures/line/1/angle.md)
- [length\(\)](./structures/line/1/length.md)
- [slope\(\)](./structures/line/1/slope.md)
- [contains\(\)](./structures/line/1/contains.md)

&nbsp;

## Example
```cpp
import std;
import xieite;

int main() {
    auto line = xieite::geometry::Line({ 0.0, 0.0 }, { 1.0, 1.0 });

    std::println("{}", line.angle());
}
```
Output:
```
0.7853981633974483
```
