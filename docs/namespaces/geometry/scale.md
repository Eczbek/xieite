# [xieite](../../xieite.md)\:\:[geometry](../../geometry.md)\:\:scale\<\>\(\)
Defined in header [<xieite/geometry/scale.hpp>](../../../include/xieite/geometry/scale.hpp)

&nbsp;

## Description
Scales a shape.

&nbsp;

## Synopsis
#### 1)
```cpp
template<typename Arithmetic_ = double>
[[nodiscard]] constexpr xieite::geometry::Point<Arithmetic_> scale(xieite::geometry::Point<Arithmetic_> point, std::conditional_t<std::floating_point<Arithmetic_>, Arithmetic_, double> scale, xieite::geometry::Point<Arithmetic_> origin = xieite::geometry::Point<Arithmetic_>()) noexcept;
```
#### 2)
```cpp
template<typename Arithmetic_ = double, xieite::concepts::LinearShape<Arithmetic_> LinearShape>
[[nodiscard]] constexpr LinearShape scale(const LinearShape& line, const std::conditional_t<std::floating_point<Arithmetic_>, Arithmetic_, double> scale, const xieite::geometry::Point<Arithmetic_> origin = xieite::geometry::Point<Arithmetic_>()) noexcept;
```
#### 3)
```cpp
template<typename Arithmetic_ = double>
[[nodiscard]] constexpr xieite::geometry::Polygon<Arithmetic_> scale(xieite::geometry::Polygon<Arithmetic_> polygon, std::conditional_t<std::floating_point<Arithmetic_>, Arithmetic_, double> scale, const xieite::geometry::Point<Arithmetic_> origin = xieite::geometry::Point<Arithmetic_>()) noexcept;
```

&nbsp;

## Example
```cpp
#include <print>
#include "xieite/geometry/point.hpp"
#include "xieite/geometry/scale.hpp"

int main() {
    auto point = xieite::geometry::Point(1.0, 1.0);

    point = xieite::geometry::scale(point, 2.0);

    std::println("({}, {})", point.x, point.y);
}
```
Possible output:
```
(2, 2)
```
