# [`xieite`](../../README.md)`::`[`geometry`](../../docs/geometry.md)`::getDistance`
Defined in header [`<xieite/geometry/getDistance.hpp>`](../../include/xieite/geometry/getDistance.hpp)

<br/>

Calculates the distance between two points.

<br/><br/>

## Synopsis

<br/>

```cpp
[[nodiscard]]
constexpr double getDistance(xieite::geometry::Point point1, xieite::geometry::Point point2) noexcept;
```
### Parameters
- `point1` - A `xieite::geometry::Point` copy
- `point2` - Also a `xieite::geometry::Point` copy
### Return value
- `double` - Distance between the points

<br/><br/>

## Example
```cpp
#include <iostream>
#include <xieite/geometry/Point.hpp>
#include <xieite/geometry/getDistance.hpp>

int main() {
	xieite::geometry::Point point1(0.0, 0.0);
	xieite::geometry::Point point2(3.0, 4.0);

	std::cout << xieite::geometry::getDistance(point1, point2) << '\n';
}
```
Output:
```
5
```

<br/><br/>

## See also
- [`xieite::geometry::Point`](../../docs/geometry/Point.md)