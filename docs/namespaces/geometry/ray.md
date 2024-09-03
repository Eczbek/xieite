# [xieite](../../xieite.md)\:\:[geometry](../../geometry.md)\:\:Ray\<\> \{\}
Defined in fragment [xieite:geometry.Ray](../../../src/geometry/ray.cpp)

&nbsp;

## Description
A structure for representing a ray.

&nbsp;

## Synopsis
#### 1)
```cpp
template<xieite::concepts::Arithmetic Arithmetic = double>
struct Ray {
    xieite::geometry::Point<Arithmetic> start;
    xieite::geometry::Point<Arithmetic> end;

    constexpr Ray(xieite::geometry::Point<Arithmetic>, xieite::geometry::Point<Arithmetic>) noexcept;

    constexpr Ray(xieite::geometry::Point<Arithmetic>, std::conditional_t<std::floating_point<Arithmetic>, Arithmetic, double>) noexcept;

    template<typename OtherArithmetic>
    explicit(false) constexpr operator xieite::geometry::Ray<OtherArithmetic>() const noexcept;

    friend constexpr bool operator==(const xieite::geometry::Ray<Arithmetic>&, const xieite::geometry::Ray<Arithmetic>&) noexcept;

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
- [Ray](./structures/ray/1/operators/constructor.md)
- [operator typename](./structures/ray/1/operators/cast.md)
- [operator==](./structures/ray/1/operators/equal.md)
- [angle](./structures/ray/1/angle.md)
- [length](./structures/ray/1/length.md)
- [slope](./structures/ray/1/slope.md)
- [contains](./structures/ray/1/contains.md)

&nbsp;

## Example
```cpp
import std;
import xieite;

int main() {
    auto ray = xieite::geometry::Ray({ 0.0, 0.0 }, { 1.0, 1.0 });

    auto point = xieite::geometry::Point(-1.0, -1.0);

    std::println("{}", ray.contains(point));
}
```
Output:
```
false
```
