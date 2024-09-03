# [xieite](../../xieite.md)\:\:[geometry](../../geometry.md)\:\:translate\<\>\(\)
Defined in fragment [xieite:geometry.translate](../../../src/geometry/translate.cpp)

&nbsp;

## Description
Translates a shape.

&nbsp;

## Synopsis
#### 1)
```cpp
template<typename Arithmetic = double>
[[nodiscard]] constexpr xieite::geometry::Point<Arithmetic> translate(xieite::geometry::Point<Arithmetic> point, xieite::geometry::Point<Arithmetic> difference) noexcept;
```
#### 2)
```cpp
template<typename Arithmetic = double, xieite::concepts::LinearShape<Arithmetic> LinearShape>
[[nodiscard]] constexpr LinearShape translate(const LinearShape& line, xieite::geometry::Point<Arithmetic> difference) noexcept;
```
#### 3)
```cpp
template<typename Arithmetic = double>
[[nodiscard]] constexpr xieite::geometry::Polygon<Arithmetic> translate(xieite::geometry::Polygon<Arithmetic> polygon, xieite::geometry::Point<Arithmetic> difference) noexcept;
```

&nbsp;

## Example
```cpp
import std;
import xieite;

int main() {
    auto point = xieite::geometry::Point(3.0, 4.0);

    point = xieite::geometry::translate(point, { 5.0, 6.0 });

    std::println("({}, {})", point.x, point.y);
}
```
Possible output:
```
(8, 10)
```
