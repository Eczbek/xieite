# [xieite](../../xieite.md)\:\:[geometry](../../geometry.md)\:\:translate\<\>\(\)
Defined in header [<xieite/geometry/translate.hpp>](../../../include/xieite/geometry/translate.hpp)

&nbsp;

## Description
Translates a shape.

&nbsp;

## Synopsis
#### 1)
```cpp
template<typename Arithmetic_ = double>
[[nodiscard]] constexpr xieite::geometry::Point<Arithmetic_> translate(xieite::geometry::Point<Arithmetic_> point, xieite::geometry::Point<Arithmetic_> difference) noexcept;
```
#### 2)
```cpp
template<typename Arithmetic_ = double, xieite::concepts::LinearShape<Arithmetic_> LinearShape>
[[nodiscard]] constexpr LinearShape translate(const LinearShape& line, xieite::geometry::Point<Arithmetic_> difference) noexcept;
```
#### 3)
```cpp
template<typename Arithmetic_ = double>
[[nodiscard]] constexpr xieite::geometry::Polygon<Arithmetic_> translate(xieite::geometry::Polygon<Arithmetic_> polygon, xieite::geometry::Point<Arithmetic_> difference) noexcept;
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
