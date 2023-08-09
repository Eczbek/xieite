# [xieite](../xieite.md)\:\:[geometry](../geometry.md)\:\:reflect
Defined in header [<xieite/geometry/reflect.hpp>](../../include/xieite/geometry/reflect.hpp)

&nbsp;

## Description
Reflects a shape across any line.

&nbsp;

## Synopses
#### 1)
```cpp
template<xieite::concepts::LinearShape LinearShape>
[[nodiscard]]
constexpr xieite::geometry::Point reflect(xieite::geometry::Point point, const LinearShape& mirror) noexcept;
```
#### 2)
```cpp
template<xieite::concepts::LinearShape LinearShape1, xieite::concepts::LinearShape LinearShape2>
[[nodiscard]]
constexpr LinearShape1 reflect(const LinearShape1& line, const LinearShape2& mirror) noexcept;
```
#### 3)
```cpp
template<xieite::concepts::LinearShape LinearShape>
[[nodiscard]]
constexpr xieite::geometry::Polygon reflect(xieite::geometry::Polygon polygon, const LinearShape& mirror) noexcept;
```
