# [xieite](../xieite.md)\:\:[geometry](../geometry.md)\:\:translate
Defined in header [<xieite/geometry/translate.hpp>](../../include/xieite/geometry/translate.hpp)

&nbsp;

## Description
Translates a shape

&nbsp;

## Synopses

&nbsp;

```cpp
[[nodiscard]]
constexpr xieite::geometry::Point translate(xieite::geometry::Point point, xieite::geometry::Point difference) noexcept;
```
#### Function parameters
- `point` - A `xieite::geometry::Point`
- `difference` - A `xieite::geometry::Point`
#### Return type
- new translated `xieite::geometry::Point`

&nbsp;

```cpp
template<xieite::concepts::LinearShape LinearShape>
[[nodiscard]]
constexpr LinearShape translate(const LinearShape& line, xieite::geometry::Point difference) noexcept;
```
#### Template parameters
- `LinearShape` - The type of the passed linear shape satisfying `xieite::concepts::LinearShape`
#### Function parameters
- `linearShape` - A `LinearShape` constant reference
- `difference` - A `xieite::geometry::Point`
#### Return type
- new translated `LinearShape`

&nbsp;

```cpp
[[nodiscard]]
constexpr xieite::geometry::Polygon translate(xieite::geometry::Polygon polygon, xieite::geometry::Point difference) noexcept;
```
#### Function parameters
- `polygon` - A `xieite::geometry::Polygon`
- `difference` - A `xieite::geometry::Point`
#### Return type
- new translated `xieite::geometry::Polygon`
