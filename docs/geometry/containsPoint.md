# `xieite::geometry::containsPoint`
Defined in header [`<xieite/geometry/containsPoint.hpp>`](../../include/xieite/geometry/containsPoint.hpp)

<br/>

Checks whether a point lies within or on the border of a shape.

<br/><br/>

## Synopses

<br/>

```cpp
[[nodiscard]]
constexpr bool containsPoint(const xieite::geometry::Line& line, xieite::geometry::Point point) noexcept;
```
### Parameters
- `line` - A `xieite::geometry::Line` constant reference to check for a point on
- `point` - A `xieite::geometry::Point` copy, the point to check for
### Return value
- `bool` - Whether or not the point lies within the shape

<br/>

```cpp
[[nodiscard]]
constexpr bool containsPoint(const xieite::geometry::Ray& ray, xieite::geometry::Point point) noexcept;
```
### Parameters
- `ray` - A `xieite::geometry::Ray` constant reference to check for a point on
- `point` - A `xieite::geometry::Point` copy, the point to check for
### Return value
- `bool` - Whether or not the point lies within the shape

<br/>

```cpp
[[nodiscard]]
constexpr bool containsPoint(const xieite::geometry::Segment& segment, xieite::geometry::Point point) noexcept;
```
### Parameters
- `segment` - A `xieite::geometry::Segment` constant reference to check for a point on
- `point` - A `xieite::geometry::Point` copy, the point to check for
### Return value
- `bool` - Whether or not the point lies within the shape

<br/>

```cpp
[[nodiscard]]
constexpr bool containsPoint(const xieite::geometry::Polygon& polygon, xieite::geometry::Point point) noexcept;
```
### Parameters
- `polygon` - A `xieite::geometry::Polygon` constant reference to check for a point in
- `point` - A `xieite::geometry::Point` copy, the point to check for
### Return value
- `bool` - Whether or not the point lies within the shape

<br/>

```cpp
[[nodiscard]]
constexpr bool containsPoint(const xieite::geometry::Ellipse& ellipse, xieite::geometry::Point point) noexcept;
```
### Parameters
- `ellipse` - A `xieite::geometry::Ellipse` constant reference to check for a point in
- `point` - A `xieite::geometry::Point` copy, the point to check for
### Return value
- `bool` - Whether or not the point lies within the shape

<br/>

```cpp
[[nodiscard]]
constexpr bool containsPoint(const xieite::geometry::Circle& circle, xieite::geometry::Point point) noexcept;
```
### Parameters
- `circle` - A `xieite::geometry::Circle` constant reference to check for a point in
- `point` - A `xieite::geometry::Point` copy, the point to check for
### Return value
- `bool` - Whether or not the point lies within the shape

<br/><br/>

## Example
```cpp
#include <iostream>
#include <xieite/geometry/Polygon.hpp>
#include <xieite/geometry/containsPoint.hpp>

int main() {
	xieite::geometry::Polygon square({
		{ -1.0, -1.0 },
		{ 1.0, -1.0 },
		{ 1.0, 1.0 },
		{ -1.0, 1.0 }
	});

	std::cout << std::boolalpha
		<< xieite::geometry::containsPoint(square, { 0.0, 0.0 }) << '\n';
}
```
Output:
```
true
```

<br/><br/>

## See also
- [`xieite::geometry::Circle`](../../docs/geometry/Circle.md)
- [`xieite::geometry::Ellipse`](../../docs/geometry/Ellipse.md)
- [`xieite::geometry::Line`](../../docs/geometry/Line.md)
- [`xieite::geometry::Point`](../../docs/geometry/Point.md)
- [`xieite::geometry::Polygon`](../../docs/geometry/Polygon.md)
- [`xieite::geometry::Ray`](../../docs/geometry/Ray.md)
- [`xieite::geometry::Segment`](../../docs/geometry/Segment.md)
