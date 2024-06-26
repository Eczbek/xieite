# [xieite](../../xieite.md)\:\:[geometry](../../geometry.md)\:\:reflect\<\>\(\)
Defined in header [<xieite/geometry/reflect.hpp>](../../../include/xieite/geometry/reflect.hpp)

&nbsp;

## Description
Reflects a shape across a "mirror" line.

&nbsp;

## Synopsis
#### 1)
```cpp
template<typename Arithmetic_ = double, xieite::concepts::LinearShape<Arithmetic_> LinearShape>
[[nodiscard]] constexpr xieite::geometry::Point<Arithmetic_> reflect(xieite::geometry::Point<Arithmetic_> point, const LinearShape& mirror) noexcept;
```
#### 2)
```cpp
template<typename Arithmetic_ = double, xieite::concepts::LinearShape<Arithmetic_> LinearShape1, xieite::concepts::LinearShape<Arithmetic_> LinearShape2>
[[nodiscard]] constexpr LinearShape1 reflect(const LinearShape1& line, const LinearShape2& mirror) noexcept;
```
#### 3)
```cpp
template<typename Arithmetic_ = double, xieite::concepts::LinearShape<Arithmetic_> LinearShape>
[[nodiscard]] constexpr xieite::geometry::Polygon<Arithmetic_> reflect(xieite::geometry::Polygon<Arithmetic_> polygon, const LinearShape& mirror) noexcept;
```

&nbsp;

## Example
```cpp
#include <print>
#include "xieite/geometry/line.hpp"
#include "xieite/geometry/point.hpp"
#include "xieite/geometry/reflect.hpp"

int main() {
    auto point = xieite::geometry::Point(1.0, 2.0);

    auto mirror = xieite::geometry::Line({ 0.0, 0.0 }, { 0.0, 1.0 });

    point = xieite::geometry::reflect(point, mirror);

    std::println("({}, {})", point.x, point.y);
}
```
Possible output:
```
(-1, 2)
```
