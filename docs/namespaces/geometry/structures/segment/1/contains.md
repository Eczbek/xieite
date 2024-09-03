# [xieite](../../../../../xieite.md)\:\:[geometry](../../../../../geometry.md)\:\:[Segment<Arithmetic>](../../../segment.md)\:\:contains\(\)
Defined in fragment [xieite:geometry.Segment](../../../../../../src/geometry/segment.cpp)

&nbsp;

## Description
Checks whether a segment contains another geometrical element.

&nbsp;

## Synopsis
#### 1)
```cpp
[[nodiscard]] constexpr bool contains(const xieite::geometry::Point<Arithmetic> point) const noexcept;
```
#### 2)
```cpp
[[nodiscard]] constexpr bool contains(const xieite::geometry::Line<Arithmetic>&) const noexcept;
```
Always returns `false`.
#### 3)
```cpp
[[nodiscard]] constexpr bool contains(const xieite::geometry::Ray<Arithmetic>&) const noexcept;
```
Always returns `false`.
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
import std;
import xieite;

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
