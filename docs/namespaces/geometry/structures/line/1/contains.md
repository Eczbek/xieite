# [xieite](../../../../../xieite.md)\:\:[geometry](../../../../../geometry.md)\:\:[Line<Number>](../../../line.md)\:\:contains
Defined in header [<xieite/geometry/line.hpp>](../../../../../../include/xieite/geometry/line.hpp)

&nbsp;

## Description
Checks whether a line contains another geometrical element.

&nbsp;

## Synopsis
#### 1)
```cpp
[[nodiscard]] constexpr bool contains(xieite::geometry::Point<Number> point) const noexcept;
```
#### 2)
```cpp
[[nodiscard]] constexpr bool contains(const xieite::geometry::Line<Number>& line) const noexcept;
```
#### 3)
```cpp
[[nodiscard]] constexpr bool contains(const xieite::geometry::Ray<Number>& ray) const noexcept;
```
#### 4)
```cpp
[[nodiscard]] constexpr bool contains(const xieite::geometry::Segment<Number>& segment) const noexcept;
```
#### 5)
```cpp
[[nodiscard]] constexpr bool contains(const xieite::geometry::Polygon<Number>& polygon) const noexcept;
```

&nbsp;

## Example
```cpp
#include <print>
#include "xieite/geometry/line.hpp"
#include "xieite/geometry/point.hpp"

int main() {
    auto line = xieite::geometry::Line({ 0.0, 0.0 }, { 1.0, 1.0 });
    auto point = xieite::geometry::Point(-1.0, -1.0);

    std::println("{}", line.contains(point));
}
```
Output:
```
true
```
