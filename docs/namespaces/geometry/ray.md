# [xieite](../../xieite.md)\:\:[geometry](../../geometry.md)\:\:Ray
Defined in header [<xieite/geometry/ray.hpp>](../../../include/xieite/geometry/ray.hpp)

&nbsp;

## Description
A structure for representing a ray.

&nbsp;

## Synopsis
#### 1)
```cpp
template<xieite::concepts::Arithmetic Number = double>
struct Ray {
    xieite::geometry::Point<Number> start;
    xieite::geometry::Point<Number> end;

    constexpr Ray(xieite::geometry::Point<Number>, xieite::geometry::Point<Number>) noexcept;

    constexpr Ray(xieite::geometry::Point<Number>, std::conditional_t<std::floating_point<Number>, Number, double>) noexcept;

    template<typename OtherNumber>
    constexpr operator xieite::geometry::Ray<OtherNumber>() const noexcept;

    friend constexpr bool operator==(const xieite::geometry::Ray<Number>&, const xieite::geometry::Ray<Number>&) noexcept;

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
##### Member variables
- start
- end
##### Member functions
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
#include <print>
#include "xieite/geometry/point.hpp"
#include "xieite/geometry/ray.hpp"

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
