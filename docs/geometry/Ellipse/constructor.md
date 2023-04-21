# [`xieite`](../../../README.md)`::`[`geometry`](../../../docs/geometry.md)`::`[`Ellipse`](../../../docs/geoemtry/Ellipse.md)`::Ellipse`
Defined in header [`<xieite/geometry/Ellipse.hpp>`](../../../include/xieite/geometry/Ellipse.hpp)

<br/>

Constructs a `xieite::geometry::Ellipse`.

<br/><br/>

## Synopsis

<br/>

```cpp
constexpr Ellipse(xieite::geometry::Point center, xieite::geometry::Point radii, double rotation = 0.0) noexcept;
```
### Parameters
- `center` - A `xieite::geometry::Point` copy, determining the center of the ellipse
- `radii` - A `xieite::geometry::Point` copy, determining the ellipse's radii
- `rotation` - A `double` copy for the ellipse's rotation, in radians

<br/><br/>

## See also
- [`xieite::geometry::Point`](../../../docs/geometry/Point.md)
