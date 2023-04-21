# [`xieite`](../../README.md)`::`[`geometry`](../../docs/geometry.md)`::getArea`
Defined in header [`<xieite/geometry/getArea.hpp>`](../../include/xieite/geometry/getArea.hpp)

<br/>

Calculates the area of a shape.

<br/><br/>

## Synopses

<br/>

```cpp
[[nodiscard]]
constexpr double getArea(const xieite::geometry::Polygon& polygon) noexcept;
```
### Parameters
- `polygon` - A `xieite::geometry::Polygon` constant reference
### Return value
- `double` - Area of the shape

<br/>

```cpp
[[nodiscard]]
constexpr double getArea(const xieite::geometry::Ellipse& ellipse) noexcept;
```
### Parameters
- `ellipse` - A `xieite::geometry::Ellipse` constant reference
### Return value
- `double` - Area of the shape

<br/>

```cpp
[[nodiscard]]
constexpr double getArea(const xieite::geometry::Circle& circle) noexcept;
```
### Parameters
- `circle` - A `xieite::geometry::Circle` constant reference
### Return value
- `double` - Area of the shape

<br/><br/>

## Example
```cpp
#include <iostream>
#include <xieite/geometry/Circle.hpp>
#include <xieite/geometry/Point.hpp>
#include <xieite/geometry/getArea.hpp>

int main() {
	xieite::geometry::Point center(0.0, 0.0);

	xieite::geometry::Circle circle(center, 1.0);

	std::cout << xieite::geometry::getArea(circle) << '\n';
}
```

<br/><br/>

## See also
- [`xieite::geometry::Circle`](../../docs/geometry/Circle.md)
- [`xieite::geometry::Ellipse`](../../docs/geometry/Ellipse.md)
- [`xieite::geometry::Polygon`](../../docs/geometry/Polygon.md)
