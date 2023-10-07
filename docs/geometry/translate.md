# [xieite](../xieite.md)\:\:[geometry](../geometry.md)\:\:translate
Defined in header [<xieite/geometry/translate.hpp>](../../include/xieite/geometry/translate.hpp)

&nbsp;

## Description
Translates a shape.

&nbsp;

## Synopses
#### 1)
```cpp
[[nodiscard]] constexpr xieite::geometry::Point translate(xieite::geometry::Point point, xieite::geometry::Point difference) noexcept;
```
#### 2)
```cpp
template<xieite::concepts::LinearShape LinearShape>
[[nodiscard]] constexpr LinearShape translate(const LinearShape& line, xieite::geometry::Point difference) noexcept;
```
#### 3)
```cpp
[[nodiscard]] constexpr xieite::geometry::Polygon translate(xieite::geometry::Polygon polygon, xieite::geometry::Point difference) noexcept;
```
