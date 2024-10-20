# [xieite](../../xieite.md)\:\:[geometry](../../geometry.md)\:\:Point\<\> \{\}
Defined in fragment [xieite:geometry.Point](../../../src/geometry/point.cpp)

&nbsp;

## Description
A structure for representing a point.

&nbsp;

## Synopsis
#### 1)
```cpp
template<xieite::concepts::Arithmetic Arithmetic = double>
struct Point {
    Arithmetic x;
    Arithmetic y;

    constexpr Point() noexcept;

    constexpr Point(Arithmetic, Arithmetic) noexcept;

    template<typename OtherArithmetic>
    explicit(false) constexpr operator Point<OtherArithmetic>() const noexcept;

    friend constexpr bool operator==(Point, Point) noexcept;

    constexpr std::conditional_t<std::floating_point<Arithmetic>, Arithmetic, double> angleTo(Point) const noexcept;

    constexpr std::conditional_t<std::floating_point<Arithmetic>, Arithmetic, double> distanceTo(Point) const noexcept;

    constexpr std::conditional_t<std::floating_point<Arithmetic>, Arithmetic, double> slopeTo(Point) const noexcept;

    constexpr bool contains(Point) const noexcept;

    constexpr bool contains(const xieite::geometry::Line<Arithmetic>&) const noexcept;

    constexpr bool contains(const xieite::geometry::Ray<Arithmetic>&) const noexcept;

    constexpr bool contains(const xieite::geometry::Segment<Arithmetic>& segment) const noexcept;

    constexpr bool contains(const xieite::geometry::Polygon<Arithmetic>& polygon) const noexcept;
};
```
- x
- y
- [Point\(\)](./structures/point/1/operators/constructor.md)
- [operator typename\<\>\(\)](./structures/point/1/operators/cast.md)
- [operator==\(\)](./structures/point/1/operators/equal.md)
- [angleTo\(\)](./structures/point/1/angle_to.md)
- [distanceTo\(\)](./structures/point/1/distance_to.md)
- [slopeTo\(\)](./structures/point/1/slope_to.md)
- [contains\(\)](./structures/point/1/contains.md)

&nbsp;

## Example
```cpp
import std;
import xieite;

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
