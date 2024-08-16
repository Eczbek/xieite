# [xieite](../../xieite.md)\:\:[geometry](../../geometry.md)\:\:intersections\<\>\(\)
Defined in header [<xieite/geometry/intersections.hpp>](../../../include/xieite/geometry/intersections.hpp)

&nbsp;

## Description
Computes all intersections between two geometrical elements.

&nbsp;

## Synopsis
#### 1)
```cpp
template<typename Arithmetic = double>
[[nodiscard]] constexpr std::vector<xieite::geometry::Point<Arithmetic>> intersections(xieite::geometry::Point<Arithmetic>, xieite::geometry::Point<Arithmetic>) noexcept;
```
#### 2)
```cpp
template<typename Arithmetic = double, xieite::concepts::LinearShape<Arithmetic> LinearShape>
[[nodiscard]] constexpr std::vector<xieite::geometry::Point<Arithmetic>> intersections(xieite::geometry::Point<Arithmetic>, const LinearShape&) noexcept;
```
#### 3)
```cpp
template<typename Arithmetic = double>
[[nodiscard]] constexpr std::vector<xieite::geometry::Point<Arithmetic>> intersections(xieite::geometry::Point<Arithmetic>, const xieite::geometry::Polygon<Arithmetic>&) noexcept;
```
#### 4)
```cpp
template<typename Arithmetic = double, xieite::concepts::LinearShape<Arithmetic> LinearShape>
[[nodiscard]] constexpr std::vector<xieite::geometry::Point<Arithmetic>> intersections(const LinearShape&, xieite::geometry::Point<Arithmetic>) noexcept;
```
#### 5)
```cpp
template<typename Arithmetic = double, xieite::concepts::LinearShape<Arithmetic> LinearShape1, xieite::concepts::LinearShape<Arithmetic> LinearShape2>
[[nodiscard]] constexpr std::vector<xieite::geometry::Point<Arithmetic>> intersections(const LinearShape1&, const LinearShape2&) noexcept;
```
#### 6)
```cpp
template<typename Arithmetic = double, xieite::concepts::LinearShape<Arithmetic> LinearShape>
[[nodiscard]] constexpr std::vector<xieite::geometry::Point<Arithmetic>> intersections(const LinearShape&, const xieite::geometry::Polygon<Arithmetic>&) noexcept;
```
#### 7)
```cpp
template<typename Arithmetic = double>
[[nodiscard]] constexpr std::vector<xieite::geometry::Point<Arithmetic>> intersections(const xieite::geometry::Polygon<Arithmetic>&, xieite::geometry::Point<Arithmetic>) noexcept;
```
#### 8)
```cpp
template<typename Arithmetic = double, xieite::concepts::LinearShape<Arithmetic> LinearShape>
[[nodiscard]] constexpr std::vector<xieite::geometry::Point<Arithmetic>> intersections(const xieite::geometry::Polygon<Arithmetic>&, const LinearShape&) noexcept;
```
#### 9)
```cpp
template<typename Arithmetic = double>
[[nodiscard]] constexpr std::vector<xieite::geometry::Point<Arithmetic>> intersections(const xieite::geometry::Polygon<Arithmetic>&, const xieite::geometry::Polygon<Arithmetic>&) noexcept;
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
