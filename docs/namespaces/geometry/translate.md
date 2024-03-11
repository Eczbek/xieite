# [xieite](../../xieite.md)\:\:[geometry](../../geometry.md)\:\:translate\(\)
Defined in header [<xieite/geometry/translate.hpp>](../../../include/xieite/geometry/translate.hpp)

&nbsp;

## Description
Translates a shape.

&nbsp;

## Synopsis
#### 1)
```cpp
template<typename Number = double>
[[nodiscard]] constexpr xieite::geometry::Point<Number> translate(xieite::geometry::Point<Number> point, xieite::geometry::Point<Number> difference) noexcept;
```
#### 2)
```cpp
template<typename Number = double, xieite::concepts::LinearShape<Number> LinearShape>
[[nodiscard]] constexpr LinearShape translate(const LinearShape& line, xieite::geometry::Point<Number> difference) noexcept;
```
#### 3)
```cpp
template<typename Number = double>
[[nodiscard]] constexpr xieite::geometry::Polygon<Number> translate(xieite::geometry::Polygon<Number> polygon, xieite::geometry::Point<Number> difference) noexcept;
```

&nbsp;

## Example
```cpp
#include <print>
#include "xieite/geometry/point.hpp"
#include "xieite/geometry/translate.hpp"

int main() {
    auto point = xieite::geometry::Point(3.0, 4.0);

    point = xieite::geometry::translate(point, { 5.0, 6.0 });

    std::println("({}, {})", point.x, point.y);
}
```
Possible output:
```
(8, 10)
```
