# `xieite::geometry::Circle::operator==`
Defined in header [`<xieite/geometry/Circle.hpp>`](../../../include/xieite/geometry/Circle.hpp)

<br/>

Compares two ellipses to each other, or an ellipse to a circle, using `xieite::geometry::Circle::operator==`.

<br/><br/>

## Synopses

<br/>

```cpp
[[nodiscard]]
constexpr bool operator==(const xieite::geometry::Ellipse& ellipse) const noexcept;
```
### Parameters
- `ellipse` - A `xieite::geometry::Ellipse` constant reference
### Return value
- `bool` - Whether or not the compared shapes are equal

<br/>

```cpp
[[nodiscard]]
constexpr bool operator==(const xieite::geometry::Circle& circle) const noexcept;
```
### Parameters
- `circle` - A `xieite::geometry::Circle` constant reference
### Return value
- `bool` - Whether or not the compared shapes are equal

<br/><br/>

## See also
- [`xieite::geometry::Circle`](../../../docs/geometry/Circle.md)
- [`xieite::geometry::Ellipse`](../../../docs/geometry/Ellipse.md)
