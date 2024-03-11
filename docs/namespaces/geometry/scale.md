# [xieite](../../xieite.md)\:\:[geometry](../../geometry.md)\:\:scale\(\)
Defined in header [<xieite/geometry/scale.hpp>](../../../include/xieite/geometry/scale.hpp)

&nbsp;

## Description
Scales a shape.

&nbsp;

## Synopsis
#### 1)
```cpp
template<typename Number = double>
[[nodiscard]] constexpr xieite::geometry::Point<Number> scale(xieite::geometry::Point<Number> point, std::conditional_t<std::floating_point<Number>, Number, double> scale, xieite::geometry::Point<Number> origin = xieite::geometry::Point<Number>()) noexcept;
```
#### 2)
```cpp
template<typename Number = double, xieite::concepts::LinearShape<Number> LinearShape>
[[nodiscard]] constexpr LinearShape scale(const LinearShape& line, const std::conditional_t<std::floating_point<Number>, Number, double> scale, const xieite::geometry::Point<Number> origin = xieite::geometry::Point<Number>()) noexcept;
```
#### 3)
```cpp
template<typename Number = double>
[[nodiscard]] constexpr xieite::geometry::Polygon<Number> scale(xieite::geometry::Polygon<Number> polygon, std::conditional_t<std::floating_point<Number>, Number, double> scale, const xieite::geometry::Point<Number> origin = xieite::geometry::Point<Number>()) noexcept;
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
