# [xieite](../../xieite.md)\:\:[geometry](../../geometry.md)\:\:scale\<\>\(\)
Defined in fragment [xieite:geometry.scale](../../../src/geometry/scale.cpp)

&nbsp;

## Description
Scales a shape.

&nbsp;

## Synopsis
#### 1)
```cpp
template<typename Arithmetic = double>
[[nodiscard]] constexpr xieite::geometry::Point<Arithmetic> scale(xieite::geometry::Point<Arithmetic> point, std::conditional_t<std::floating_point<Arithmetic>, Arithmetic, double> scale, xieite::geometry::Point<Arithmetic> origin = xieite::geometry::Point<Arithmetic>()) noexcept;
```
#### 2)
```cpp
template<typename Arithmetic = double, xieite::concepts::LinearShape<Arithmetic> LinearShape>
[[nodiscard]] constexpr LinearShape scale(const LinearShape& line, const std::conditional_t<std::floating_point<Arithmetic>, Arithmetic, double> scale, const xieite::geometry::Point<Arithmetic> origin = xieite::geometry::Point<Arithmetic>()) noexcept;
```
#### 3)
```cpp
template<typename Arithmetic = double>
[[nodiscard]] constexpr xieite::geometry::Polygon<Arithmetic> scale(xieite::geometry::Polygon<Arithmetic> polygon, std::conditional_t<std::floating_point<Arithmetic>, Arithmetic, double> scale, const xieite::geometry::Point<Arithmetic> origin = xieite::geometry::Point<Arithmetic>()) noexcept;
```

&nbsp;

## Example
```cpp
import std;
import xieite;

int main() {
    auto point = xieite::geometry::Point(1.0, 1.0);

    point = xieite::geometry::scale(point, 2.0);

    std::println("({}, {})", point.x, point.y);
}
```
Possible output:
```
(2, 2)
```
