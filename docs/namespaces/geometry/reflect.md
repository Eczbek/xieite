# [xieite](../../xieite.md)\:\:[geometry](../../geometry.md)\:\:reflect\<\>\(\)
Defined in fragment [xieite:geometry.reflect](../../../src/geometry/reflect.cpp)

&nbsp;

## Description
Reflects a shape across a "mirror" line.

&nbsp;

## Synopsis
#### 1)
```cpp
template<typename Arithmetic = double, xieite::concepts::LinearShape<Arithmetic> LinearShape>
[[nodiscard]] constexpr xieite::geometry::Point<Arithmetic> reflect(xieite::geometry::Point<Arithmetic> point, const LinearShape& mirror) noexcept;
```
#### 2)
```cpp
template<typename Arithmetic = double, xieite::concepts::LinearShape<Arithmetic> LinearShape1, xieite::concepts::LinearShape<Arithmetic> LinearShape2>
[[nodiscard]] constexpr LinearShape1 reflect(const LinearShape1& line, const LinearShape2& mirror) noexcept;
```
#### 3)
```cpp
template<typename Arithmetic = double, xieite::concepts::LinearShape<Arithmetic> LinearShape>
[[nodiscard]] constexpr xieite::geometry::Polygon<Arithmetic> reflect(xieite::geometry::Polygon<Arithmetic> polygon, const LinearShape& mirror) noexcept;
```

&nbsp;

## Example
```cpp
import std;
import xieite;

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
