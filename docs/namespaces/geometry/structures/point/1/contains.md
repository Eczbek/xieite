# [xieite](../../../../../xieite.md)\:\:[geometry](../../../../../geometry.md)\:\:[Point<Arithmetic_>](../../../point.md)\:\:contains\(\)
Defined in header [<xieite/geometry/point.hpp>](../../../../../../include/xieite/geometry/point.hpp)

&nbsp;

## Description
Checks if a point contains another geometrical element.

&nbsp;

## Synopsis
#### 1)
```cpp
[[nodiscard]] constexpr bool contains(xieite::geometry::Point<Arithmetic_> point) const noexcept;
```
#### 2)
```cpp
[[nodiscard]] constexpr bool contains(const xieite::geometry::Line<Arithmetic_>&) const noexcept;
```
Always returns `false`.
#### 3)
```cpp
[[nodiscard]] constexpr bool contains(const xieite::geometry::Ray<Arithmetic_>&) const noexcept;
```
Always returns `false`.
#### 4)
```cpp
[[nodiscard]] constexpr bool contains(const xieite::geometry::Segment<Arithmetic_>& segment) const noexcept;
```
#### 5)
```cpp
[[nodiscard]] constexpr bool contains(const xieite::geometry::Polygon<Arithmetic_>& polygon) const noexcept;
```

&nbsp;

## Example
```cpp
#include <print>
#include "xieite/geometry/point.hpp"
#include "xieite/geometry/segment.hpp"

int main() {
    auto point = xieite::geometry::Point(0.0, 0.0);

    auto segment = xieite::geometry::Segment(point, point);

    std::println("{}", point.contains(segment));
}
```
Output:
```
true
```
