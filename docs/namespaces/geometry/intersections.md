# [xieite](../../xieite.md)\:\:[geometry](../../geometry.md)\:\:intersections\<\>\(\)
Defined in header [<xieite/geometry/intersections.hpp>](../../../include/xieite/geometry/intersections.hpp)

&nbsp;

## Description
Computes all intersections between two geometrical elements.

&nbsp;

## Synopsis
#### 1)
```cpp
template<typename Arithmetic_ = double>
[[nodiscard]] constexpr std::vector<xieite::geometry::Point<Arithmetic_>> intersections(xieite::geometry::Point<Arithmetic_>, xieite::geometry::Point<Arithmetic_>) noexcept;
```
#### 2)
```cpp
template<typename Arithmetic_ = double, xieite::concepts::LinearShape<Arithmetic_> LinearShape>
[[nodiscard]] constexpr std::vector<xieite::geometry::Point<Arithmetic_>> intersections(xieite::geometry::Point<Arithmetic_>, const LinearShape&) noexcept;
```
#### 3)
```cpp
template<typename Arithmetic_ = double>
[[nodiscard]] constexpr std::vector<xieite::geometry::Point<Arithmetic_>> intersections(xieite::geometry::Point<Arithmetic_>, const xieite::geometry::Polygon<Arithmetic_>&) noexcept;
```
#### 4)
```cpp
template<typename Arithmetic_ = double, xieite::concepts::LinearShape<Arithmetic_> LinearShape>
[[nodiscard]] constexpr std::vector<xieite::geometry::Point<Arithmetic_>> intersections(const LinearShape&, xieite::geometry::Point<Arithmetic_>) noexcept;
```
#### 5)
```cpp
template<typename Arithmetic_ = double, xieite::concepts::LinearShape<Arithmetic_> LinearShape1, xieite::concepts::LinearShape<Arithmetic_> LinearShape2>
[[nodiscard]] constexpr std::vector<xieite::geometry::Point<Arithmetic_>> intersections(const LinearShape1&, const LinearShape2&) noexcept;
```
#### 6)
```cpp
template<typename Arithmetic_ = double, xieite::concepts::LinearShape<Arithmetic_> LinearShape>
[[nodiscard]] constexpr std::vector<xieite::geometry::Point<Arithmetic_>> intersections(const LinearShape&, const xieite::geometry::Polygon<Arithmetic_>&) noexcept;
```
#### 7)
```cpp
template<typename Arithmetic_ = double>
[[nodiscard]] constexpr std::vector<xieite::geometry::Point<Arithmetic_>> intersections(const xieite::geometry::Polygon<Arithmetic_>&, xieite::geometry::Point<Arithmetic_>) noexcept;
```
#### 8)
```cpp
template<typename Arithmetic_ = double, xieite::concepts::LinearShape<Arithmetic_> LinearShape>
[[nodiscard]] constexpr std::vector<xieite::geometry::Point<Arithmetic_>> intersections(const xieite::geometry::Polygon<Arithmetic_>&, const LinearShape&) noexcept;
```
#### 9)
```cpp
template<typename Arithmetic_ = double>
[[nodiscard]] constexpr std::vector<xieite::geometry::Point<Arithmetic_>> intersections(const xieite::geometry::Polygon<Arithmetic_>&, const xieite::geometry::Polygon<Arithmetic_>&) noexcept;
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
