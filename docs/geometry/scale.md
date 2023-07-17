# [xieite](../xieite.md)::[geometry](../geometry.md)::scale
Defined in header [<xieite/geometry/scale.hpp>](../../include/xieite/geometry/scale.hpp)

<br/>

Scales a shape

<br/><br/>

## Synopses

<br/><br/>

```cpp
[[nodiscard]]
constexpr xieite::geometry::Point scale(xieite::geometry::Point point, double scale, xieite::geometry::Point pivot = xieite::geometry::Point(0, 0)) noexcept;
```
### Parameters
- `point` - A `xieite::geometry::Point` copy
- `scale` - A `double` copy
- `pivot` - A `xieite::geometry::Point` copy, is `{ 0, 0 }` by default
### Return value
- A new scaled `xieite::geometry::Point`

<br/><br/>

```cpp
template<xieite::concepts::LinearShape LinearShape>
[[nodiscard]]
constexpr LinearShape scale(const LinearShape& linearShape, double scale, xieite::geometry::Point pivot = xieite::geometry::Point(0, 0)) noexcept;
```
### Template parameters
- `LinearShape` - The type of the passed linear shape, satisfying `xieite::concepts::LinearShape`
### Parameters
- `linearShape` - A `LinearShape` constant reference
- `scale` - A `double` copy
- `pivot` - A `xieite::geometry::Point` copy, is `{ 0, 0 }` by default
### Return value
- A new scaled `LinearShape`

<br/><br/>

```cpp
[[nodiscard]]
constexpr xieite::geometry::Polygon scale(xieite::geometry::Polygon polygon, double scale, xieite::geometry::Point pivot = xieite::geometry::Point(0, 0)) noexcept;
```
### Parameters
- `polygon` - A `xieite::geometry::Polygon` constant reference
- `scale` - A `double` copy
- `pivot` - A `xieite::geometry::Point` copy, is `{ 0, 0 }` by default
### Return value
- A new scaled `xieite::geometry::Polygon`
