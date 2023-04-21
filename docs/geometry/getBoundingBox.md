# [`xieite`](../../README.md)`::`[`geometry`](../../docs/geometry.md)`::getBoundingBox`
Defined in header [`<xieite/geometry/getBoundingBox.hpp>`](../../include/xieite/geometry/getBoundingBox.hpp)

<br/>

Creates a minimal rectangle to contain an ellipse or circle. The rotation of the ellipse will not affect the rotation of the bounding box.

<br/><br/>

## Synopses

<br/>

```cpp
[[nodiscard]]
constexpr xieite::geometry::Polygon getBoundingBox(const xieite::geometry::Ellipse& ellipse) noexcept;
```
### Parameters
- `ellipse` - A `xieite::geometry::Ellipse` constant reference
### Return value
- `xieite::geometry::Polygon` - An unrotated rectangle of minimal size to contain the shape

<br/>

```cpp
[[nodiscard]]
constexpr xieite::geometry::Polygon getBoundingBox(const xieite::geometry::Circle& circle) noexcept;
```
### Parameters
- `circle` - A `xieite::geometry::Circle` constant reference
### Return value
- `xieite::geometry::Polygon` - An minimal square to contain the shape

<br/><br/>

## Example
```cpp
#include <iostream>
#include <xieite/geometry/Circle.hpp>
#include <xieite/geometry/Point.hpp>
#include <xieite/geometry/Polygon.hpp>
#include <xieite/geometry/getBoundingBox.hpp>

int main() {
	xieite::geometry::Point center(0.0, 0.0);

	xieite::geometry::Circle circle(center, 1.0);

	for (xieite::geometry::Point point : xieite::geometry::getBoundingBox(circle).points) {
		std::cout << '(' << point.x << ", " << point.y << ")\n";
	}
}
```
Output:
```
(-1, -1)
(1, -1)
(1, 1)
(-1, 1)
```

<br/><br/>

## See also
- [`xieite::geometry::Circle`](../../docs/geometry/Circle.md)
- [`xieite::geometry::Ellipse`](../../docs/geometry/Ellipse.md)
- [`xieite::geometry::Polygon`](../../docs/geometry/Polygon.md)
