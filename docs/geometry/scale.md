# [xieite](../xieite.md)\:\:[geometry](../geometry.md)\:\:scale
Defined in header [<xieite/geometry/scale.hpp>](../../include/xieite/geometry/scale.hpp)

&nbsp;

## Description
Scales a shape

&nbsp;

## Synopses

&nbsp;

```cpp
[[nodiscard]]
constexpr xieite::geometry::Point scale(xieite::geometry::Point point, double scale, xieite::geometry::Point pivot = xieite::geometry::Point(0, 0)) noexcept;
```
#### Function parameters
- `point` - A `xieite::geometry::Point`
- `scale` - A `double`
- `pivot` - A `xieite::geometry::Point`, is `{ 0, 0 }` by default
#### Return type
- new scaled `xieite::geometry::Point`

&nbsp;

```cpp
template<xieite::concepts::LinearShape LinearShape>
[[nodiscard]]
constexpr LinearShape scale(const LinearShape& linearShape, double scale, xieite::geometry::Point pivot = xieite::geometry::Point(0, 0)) noexcept;
```
#### Template parameters
- `LinearShape` - The type of the passed linear shape satisfying `xieite::concepts::LinearShape`
#### Function parameters
- `linearShape` - A `LinearShape` constant reference
- `scale` - A `double`
- `pivot` - A `xieite::geometry::Point`, is `{ 0, 0 }` by default
#### Return type
- new scaled `LinearShape`

&nbsp;

```cpp
[[nodiscard]]
constexpr xieite::geometry::Polygon scale(xieite::geometry::Polygon polygon, double scale, xieite::geometry::Point pivot = xieite::geometry::Point(0, 0)) noexcept;
```
#### Function parameters
- `polygon` - A `xieite::geometry::Polygon` constant reference
- `scale` - A `double`
- `pivot` - A `xieite::geometry::Point`, is `{ 0, 0 }` by default
#### Return type
- new scaled `xieite::geometry::Polygon`
