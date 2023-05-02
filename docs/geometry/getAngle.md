# [`xieite`](../../README.md)`::`[`geometry`](../../docs/geometry.md)`::getAngle`
Defined in header [`<xieite/geometry/getAngle.hpp>`](../../include/xieite/geometry/getAngle.hpp)

<br/>

Calculates the angle of a line or between two points, in radians.

<br/><br/>

## Synopses

<br/><br/>

```cpp
[[nodiscard]]
constexpr double getAngle(xieite::geometry::Point point1, xieite::geometry::Point point2) noexcept;
```
### Parameters
- `point1` - A `xieite::geometry::Point` copy
- `point2` - A `xieite::geometry::Point` copy
### Return value
- `double` - The angle between two points

<br/><br/>

```cpp
[[nodiscard]]
constexpr double getAngle(const xieite::concepts::LinearShape auto& linearShape) noexcept;
```
### Parameters
- `linearShape` - An `auto` constant reference, satisfying `xieite::concepts::LinearShape`
### Return value
- `double` - The angle of the linear thing

<br/><br/>

## Example
```cpp
#include <iostream>
#include <xieite/geometry/Line.hpp>
#include <xieite/geometry/Point.hpp>
#include <xieite/geometry/getAngle.hpp>

int main() {
	xieite::geometry::Point start(0.0, 0.0);
	xieite::geometry::Point end(1.0, 0.0);

	xieite::geometry::Line line(start, end);

	std::cout << xieite::geometry::getAngle(line) << '\n';
}
```
Output (rounded):
```
0
```

<br/><br/>

## See also
- [`xieite::concepts::LinearShape`](../../docs/concepts/LinearShape.md)
- [`xieite::geometry::Point`](../../docs/geometry/Point.md)
