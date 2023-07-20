# [xieite](../xieite.md)::[geometry](../geometry.md)::translate
Defined in header [<xieite/geometry/translate.hpp>](../../include/xieite/geometry/translate.hpp)

<br/>

Translates a shape

<br/><br/>

## Synopses

<br/><br/>

```cpp
[[nodiscard]]
constexpr xieite::geometry::Point translate(xieite::geometry::Point point, xieite::geometry::Point difference) noexcept;
```
### Parameters
- `point` - A `xieite::geometry::Point`
- `difference` - A `xieite::geometry::Point`
### Return value
- A new translated `xieite::geometry::Point`

<br/><br/>

```cpp
template<xieite::concepts::LinearShape LinearShape>
[[nodiscard]]
constexpr LinearShape translate(const LinearShape& line, xieite::geometry::Point difference) noexcept;
```
### Template parameters
- `LinearShape` - The type of the passed linear shape satisfying `xieite::concepts::LinearShape`
### Parameters
- `linearShape` - A `LinearShape` constant reference
- `difference` - A `xieite::geometry::Point`
### Return value
- A new translated `LinearShape`

<br/><br/>

```cpp
[[nodiscard]]
constexpr xieite::geometry::Polygon translate(xieite::geometry::Polygon polygon, xieite::geometry::Point difference) noexcept;
```
### Parameters
- `polygon` - A `xieite::geometry::Polygon`
- `difference` - A `xieite::geometry::Point`
### Return value
- A new translated `xieite::geometry::Polygon`
