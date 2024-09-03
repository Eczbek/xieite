# [xieite](../../xieite.md)\:\:[geometry](../../geometry.md)\:\:rotate\<\>\(\)
Defined in fragment [xieite:geometry.rotate](../../../src/geometry/rotate.cpp)

&nbsp;

## Description
Rotates shapes a specific angle around any pivot, clockwise.

&nbsp;

## Synopsis
#### 1)
```cpp
template<typename Arithmetic = double>
[[nodiscard]] constexpr xieite::geometry::Point<Arithmetic> rotate(xieite::geometry::Point<Arithmetic> point, std::conditional_t<std::floating_point<Arithmetic>, Arithmetic, double> angle, xieite::geometry::Point<Arithmetic> pivot = xieite::geometry::Point<Arithmetic>()) noexcept;
```
#### 2)
```cpp
template<typename Arithmetic = double, xieite::concepts::LinearShape<Arithmetic> LinearShape>
[[nodiscard]] constexpr LinearShape rotate(const LinearShape& linearShape, std::conditional_t<std::floating_point<Arithmetic>, Arithmetic, double> angle, xieite::geometry::Point<Arithmetic> pivot = xieite::geometry::Point<Arithmetic>()) noexcept;
```
#### 3)
```cpp
template<typename Arithmetic = double>
[[nodiscard]] constexpr xieite::geometry::Polygon<Arithmetic> rotate(xieite::geometry::Polygon<Arithmetic> polygon, std::conditional_t<std::floating_point<Arithmetic>, Arithmetic, double> angle, xieite::geometry::Point<Arithmetic> pivot = xieite::geometry::Point<Arithmetic>()) noexcept;
```

&nbsp;

## Example
```cpp
import std;
import xieite;

int main() {
    using namespace xieite::literals::units;

    auto line1 = xieite::geometry::Line({ 0.0, 0.0 }, { 1.0, 1.0 });

    auto line2 = xieite::geometry::rotate(line1, 90_degrees);

    std::println("{}", line1.slope());
    std::println("{}", line2.slope());
}
```
Possible output:
```
1
-1
```
