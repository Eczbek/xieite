# [xieite](../xieite.md)\:\:[geometry](../geometry.md)\:\:reflect
Defined in header [<xieite/geometry/reflect.hpp>](../../include/xieite/geometry/reflect.hpp)

&nbsp;

## Description
Reflects a shape across any line

&nbsp;

## Synopses

&nbsp;

```cpp
template<xieite::concepts::LinearShape LinearShape>
[[nodiscard]]
constexpr xieite::geometry::Point reflect(const xieite::geometry::Point point, const LinearShape& mirror) noexcept;
```
#### Template parameters
- `LinearShape` - A type satisfying `xieite::concepts::LinearShape`
#### Function parameters
- `point` - A `xieite::geometry::Point`
- `mirror` - A constant `LinearShape` reference
#### Return type
- new reflected `xieite::geometry::Point`

&nbsp;

```cpp
template<xieite::concepts::LinearShape LinearShape1, xieite::concepts::LinearShape LinearShape2>
[[nodiscard]]
constexpr LinearShape1 reflect(const LinearShape1& line, const LinearShape2& mirror) noexcept;
```
#### Template parameters
- `LinearShape1` - A type satisfying `xieite::concepts::LinearShape`
- `LinearShape2` - A type satisfying `xieite::concepts::LinearShape`
#### Function parameters
- `linearShape` - A constant `LinearShape1` reference
- `mirror` - A constant `LinearShape2` reference
#### Return type
- new reflected `LinearShape`

&nbsp;

```cpp
template<xieite::concepts::LinearShape LinearShape>
[[nodiscard]]
constexpr xieite::geometry::Polygon reflect(xieite::geometry::Polygon polygon, const LinearShape& mirror) noexcept;
```
#### Template parameters
- `LinearShape` - A type satisfying `xieite::concepts::LinearShape`
#### Function parameters
- `polygon` - A `xieite::geometry::Polygon` constant reference
- `mirror` - A constant `LinearShape` reference
#### Return type
- new reflected `xieite::geometry::Polygon`
