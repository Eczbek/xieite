# `xieite::geometry::Circle::operator==`
Defined in header [`<xieite/geometry/Circle.hpp>`](https://github.com/Eczbek/xieite/tree/main/include/xieite/geometry/Circle.hpp)

<br/>

Compares either two circles with each other, or a circle with an ellipse, but only if the ellipse has the same width as its height.

<br/><br/>

## Synopsis

<br/>

```cpp
[[nodiscard]]
constexpr bool operator==(const xieite::geometry::Circle& circle) const noexcept;
```
### Parameters
- `circle` - A `xieite::geometry::Circle` constant reference
### Return value
- `bool` - Whether or not the two compared shapes are equal

<br/>


```cpp
[[nodiscard]]
constexpr bool operator==(const xieite::geometry::Ellipse& ellipse) const noexcept;
```
### Parameters
- `ellipse` - A `xieite::geometry::Ellipse` constant reference
### Return value
- `bool` - Whether or not the two compared shapes are equal

<br/><br/>

## See also
- [`xieite::geometry::Circle`](https://github.com/Eczbek/xieite/tree/main/docs/geometry/Circle.md)
- [`xieite::geometry::Ellipse`](https://github.com/Eczbek/xieite/tree/main/docs/geometry/Ellipse.md)
