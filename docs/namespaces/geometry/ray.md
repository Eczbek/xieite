# [xieite](../../xieite.md)\:\:[geometry](../../geometry.md)\:\:Ray\<\> \{\}
Defined in header [<xieite/geometry/ray.hpp>](../../../include/xieite/geometry/ray.hpp)

&nbsp;

## Description
A structure for representing a ray.

&nbsp;

## Synopsis
#### 1)
```cpp
template<xieite::concepts::Arithmetic Arithmetic_ = double>
struct Ray {
    xieite::geometry::Point<Arithmetic_> start;
    xieite::geometry::Point<Arithmetic_> end;

    constexpr Ray(xieite::geometry::Point<Arithmetic_>, xieite::geometry::Point<Arithmetic_>) noexcept;

    constexpr Ray(xieite::geometry::Point<Arithmetic_>, std::conditional_t<std::floating_point<Arithmetic_>, Arithmetic_, double>) noexcept;

    template<typename OtherArithmetic_>
    constexpr operator xieite::geometry::Ray<OtherArithmetic_>() const noexcept;

    friend constexpr bool operator==(const xieite::geometry::Ray<Arithmetic_>&, const xieite::geometry::Ray<Arithmetic_>&) noexcept;

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
