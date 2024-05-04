# [xieite](../../../../../xieite.md)\:\:[geometry](../../../../../geometry.md)\:\:[Polygon<Arithmetic_>](../../../polygon.md)\:\:contains\(\)
Defined in header [<xieite/geometry/polygon.hpp>](../../../../../../include/xieite/geometry/polygon.hpp)

&nbsp;

## Description
Checks whether a polygon contains another geometrical element.

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
#include "xieite/geometry/polygon.hpp"

int main() {
    auto polygon = xieite::geometry::Polygon({
        { 0.0, 0.0 },
        { 2.0, 0.0 },
        { 2.0, 2.0 },
        { 0.0, 2.0 }
    });

    std::println("{}", polygon.contains(xieite::geometry::Point(1.0, 1.0)));
}
```
Output:
```
true
```
