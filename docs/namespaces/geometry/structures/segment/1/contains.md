# [xieite](../../../../../xieite.md)\:\:[geometry](../../../../../geometry.md)\:\:[Segment<Arithmetic_>](../../../segment.md)\:\:contains\(\)
Defined in header [<xieite/geometry/segment.hpp>](../../../../../../include/xieite/geometry/segment.hpp)

&nbsp;

## Description
Checks whether a segment contains another geometrical element.

&nbsp;

## Synopsis
#### 1)
```cpp
[[nodiscard]] constexpr bool contains(const xieite::geometry::Point<Arithmetic_> point) const noexcept;
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
    auto segment = xieite::geometry::Segment({ 0.0, 0.0 }, { 1.0, 1.0 });

    auto point = xieite::geometry::Point(2.0, 2.0);

    std::println("{}", segment.contains(point));
}
```
Output:
```
false
```
