# [xieite](../xieite.md)::[geometry](../geometry.md)::reflect
Defined in header [<xieite/geometry/reflect.hpp>](../../include/xieite/geometry/reflect.hpp)

<br/>

Reflects a shape across any line

<br/><br/>

## Synopses

<br/><br/>

```cpp
[[nodiscard]]
constexpr xieite::geometry::Point reflect(xieite::geometry::Point point, const xieite::concepts::LinearShape auto& mirror) noexcept;
```
### Parameters
- `point` - A `xieite::geometry::Point` copy
- `mirror` - An `auto` constant reference, satisfying `xieite::concepts::LinearShape`
### Return value
- A new reflected `xieite::geometry::Point`

<br/><br/>

```cpp
template<xieite::concepts::LinearShape LinearShape>
[[nodiscard]]
constexpr LinearShape reflect(const LinearShape& line, const xieite::concepts::LinearShape auto& mirror) noexcept;
```
### Template parameters
- `LinearShape` - The type of the passed linear shape, satisfying `xieite::concepts::LinearShape`
### Parameters
- `linearShape` - A `LinearShape` constant reference
- `mirror` - An `auto` constant reference, satisfying `xieite::concepts::LinearShape`
### Return value
- A new reflected `LinearShape`

<br/><br/>

```cpp
[[nodiscard]]
constexpr xieite::geometry::Polygon reflect(xieite::geometry::Polygon polygon, const xieite::concepts::LinearShape auto& mirror) noexcept;
```
### Parameters
- `polygon` - A `xieite::geometry::Polygon` constant reference
- `mirror` - An `auto` constant reference, satisfying `xieite::concepts::LinearShape`
### Return value
- A new reflected `xieite::geometry::Polygon`
