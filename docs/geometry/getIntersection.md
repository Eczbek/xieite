# [`xieite`](../../README.md)`::`[`geometry`](../../docs/geometry.md)`::getIntersection`
Defined in header [`<xieite/geometry/getIntersection.hpp>`](../../include/xieite/geometry/getIntersection.hpp)

<br/>

Finds a possible intersection between two lines.

<br/><br/>

## Synopsis

<br/>

```cpp
[[nodiscard]]
constexpr std::optional<xieite::geometry::Point> getIntersection(const xieite::concepts::LinearShape auto& linearShape1, const xieite::concepts::LinearShape auto& linearShape2) noexcept;
```
### Parameters
- `linearShape1` - An `auto` constant reference, satisfying `xieite::concepts::LinearShape`
- `linearShape2` - An `auto` constant reference, satisfying `xieite::concepts::LinearShape`
### Return value
- `std::optional` of `xieite::geometry::Point` - The intersection, if it exists

<br/><br/>

## Example
```cpp
#include <iostream>
#include <xieite/geometry/Line.hpp>
#include <xieite/geometry/Point.hpp>
#include <xieite/geometry/getIntersection.hpp>

int main() {
	xieite::geometry::Point start1(2.0, 0.0);
	xieite::geometry::Point end1(-1.0, 1.0);
	xieite::geometry::Point start2(0.0, 2.0);
	xieite::geometry::Point end2(1.0, -1.0);

	xieite::geometry::Line line1(start1, end1);
	xieite::geometry::Line line2(start2, end2);

	std::optional<xieite::geometry::Point> point = xieite::geometry::getIntersection(line1, line2);

	if (point.has_value()) {
		xieite::geometry::Point value = point.value();

		std::cout << '(' << value.x << ", " << value.y << ")\n";
	}
}
```
Output:
```
(1, 1)
```

<br/><br/>

## See also
- [`xieite::geometry::Point`](../../docs/geometry/Point.md)
