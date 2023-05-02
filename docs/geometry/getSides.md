# [`xieite`](../../README.md)`::`[`geometry`](../../docs/geometry.md)`::getSides`
Defined in header p`<xieite/geometry/getSides.hpp>`](../../include/xieite/geometry/getSides.hpp)

<br/>

Creates line segments between the points of a polygon.

<br/><br/>

## Synopsis

<br/><br/>

```cpp
[[nodiscard]]
constexpr std::vector<xieite::geometry::Segment> getSides(const xieite::geometry::Polygon& polygon) noexcept;
```
### Parameters
- `polygon` - A `xieite::geometry::Polygon` constant reference
### Return value


<br/><br/>

## Example
```cpp
#include <iostream>
#include <xieite/geometry/Polygon.hpp>
#include <xieite/geometry/Segment.hpp>
#include <xieite/geometry/getLength.hpp>
#include <xieite/geometry/getSides.hpp>

int main() {
	xieite::geometry::Polygon rectangle {
		{ 0.0, 0.0 },
		{ 3.0, 0.0 },
		{ 3.0, 2.0 },
		{ 0.0, 2.0 }
	};

	for (xieite::geometry::Segment& side : xieite::geometry::getSides(rectangle)) {
		std::cout
			<< xieite::geometry::getLength(side)
			<< '\n';
	}
}
```
Output:
```
3
2
3
2
```
