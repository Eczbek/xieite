# [xieite](../../xieite.md)\:\:[geometry](../../geometry.md)\:\:intersections\(\)
Defined in header [<xieite/geometry/intersections.hpp>](../../../include/xieite/geometry/intersections.hpp)

&nbsp;

## Description
Computes all intersections between two geometrical elements.

&nbsp;

## Synopsis
#### 1)
```cpp
template<typename Number = double>
[[nodiscard]] constexpr std::vector<xieite::geometry::Point<Number>> intersections(xieite::geometry::Point<Number>, xieite::geometry::Point<Number>) noexcept;
```
#### 2)
```cpp
template<typename Number = double, xieite::concepts::LinearShape<Number> LinearShape>
[[nodiscard]] constexpr std::vector<xieite::geometry::Point<Number>> intersections(xieite::geometry::Point<Number>, const LinearShape&) noexcept;
```
#### 3)
```cpp
template<typename Number = double>
[[nodiscard]] constexpr std::vector<xieite::geometry::Point<Number>> intersections(xieite::geometry::Point<Number>, const xieite::geometry::Polygon<Number>&) noexcept;
```
#### 4)
```cpp
template<typename Number = double, xieite::concepts::LinearShape<Number> LinearShape>
[[nodiscard]] constexpr std::vector<xieite::geometry::Point<Number>> intersections(const LinearShape&, xieite::geometry::Point<Number>) noexcept;
```
#### 5)
```cpp
template<typename Number = double, xieite::concepts::LinearShape<Number> LinearShape1, xieite::concepts::LinearShape<Number> LinearShape2>
[[nodiscard]] constexpr std::vector<xieite::geometry::Point<Number>> intersections(const LinearShape1&, const LinearShape2&) noexcept;
```
#### 6)
```cpp
template<typename Number = double, xieite::concepts::LinearShape<Number> LinearShape>
[[nodiscard]] constexpr std::vector<xieite::geometry::Point<Number>> intersections(const LinearShape&, const xieite::geometry::Polygon<Number>&) noexcept;
```
#### 7)
```cpp
template<typename Number = double>
[[nodiscard]] constexpr std::vector<xieite::geometry::Point<Number>> intersections(const xieite::geometry::Polygon<Number>&, xieite::geometry::Point<Number>) noexcept;
```
#### 8)
```cpp
template<typename Number = double, xieite::concepts::LinearShape<Number> LinearShape>
[[nodiscard]] constexpr std::vector<xieite::geometry::Point<Number>> intersections(const xieite::geometry::Polygon<Number>&, const LinearShape&) noexcept;
```
#### 9)
```cpp
template<typename Number = double>
[[nodiscard]] constexpr std::vector<xieite::geometry::Point<Number>> intersections(const xieite::geometry::Polygon<Number>&, const xieite::geometry::Polygon<Number>&) noexcept;
```

&nbsp;

## Example
```cpp
#include <print>
#include "xieite/geometry/intersections.hpp"
#include "xieite/geometry/line.hpp"

int main() {
    auto line1 = xieite::geometry::Line({ 0.0, 0.0 }, { 2.0, 2.0 });
    auto line2 = xieite::geometry::Line({ 0.0, 2.0 }, { 2.0, 0.0 });

    for (auto point : xieite::geometry::intersections(line1, line2)) {
        std::println("({}, {})", point.x, point.y);
    }
}
```
Output:
```
(1, 1)
```
