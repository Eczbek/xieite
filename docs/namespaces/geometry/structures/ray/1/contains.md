# [xieite](../../../../../xieite.md)\:\:[geometry](../../../../../geometry.md)\:\:[Ray<Arithmetic>](../../../ray.md)\:\:contains\(\)
Defined in header [<xieite/geometry/ray.hpp>](../../../../../../include/xieite/geometry/ray.hpp)

&nbsp;

## Description
Checks whether a ray contains another geometrical element.

&nbsp;

## Synopsis
#### 1)
```cpp
[[nodiscard]] constexpr bool contains(xieite::geometry::Point<Arithmetic> point) const noexcept;
```
#### 2)
```cpp
[[nodiscard]] constexpr bool contains(const xieite::geometry::Line<Arithmetic>&) const noexcept;
```
Always returns `false`.
#### 3)
```cpp
[[nodiscard]] constexpr bool contains(const xieite::geometry::Ray<Arithmetic>& ray) const noexcept;
```
#### 4)
```cpp
[[nodiscard]] constexpr bool contains(const xieite::geometry::Segment<Arithmetic>& segment) const noexcept;
```
#### 5)
```cpp
[[nodiscard]] constexpr bool contains(const xieite::geometry::Polygon<Arithmetic>& polygon) const noexcept;
```

&nbsp;

## Example
```cpp
#include <print>
#include "xieite/geometry/point.hpp"
#include "xieite/geometry/ray.hpp"

int main() {
    auto ray = xieite::geometry::Ray({ 0.0, 0.0 }, { 1.0, 1.0 });

    auto point = xieite::geometry::Point(-1.0, -1.0);

    std::println("{}", ray.contains(point));
}
```
Output:
```
false
```
