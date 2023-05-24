# [`xieite`](../../README.md)`::`[`geometry`](../../docs/geometry.md)`::Polygon`
Defined in header [`<xieite/geometry/Polygon.hpp>`](../../include/xieite/geometry/Polygon.hpp)

<br/>

A struct representing a polygon.

<br/><br/>

## Synopsis

<br/>

```cpp
struct Polygon final {
	std::vector<xieite::geometry::Point> points;

	constexpr Polygon(const xieite::concepts::RangeOf<xieite::geometry::Point> auto&);

	constexpr bool operator==(const xieite::geometry::Polygon&) const;
};
```
### Member objects
- `points` - A `std::vector` of `xieite::geometry::Point`s
### Member functions
- [`Polygon`](../../docs/geometry/Polygon/constructor.md)
- [`operator==`](../../docs/geometry/Polygon/operatorEquals.md)

<br/><br/>

## Example
```cpp
#include <iostream>
#include <xieite/geometry/Polygon.hpp>
#include <xieite/geometry/getArea.hpp>

int main() {
	std::cout
		<< xieite::geometry::getArea(xieite::geometry::Polygon({
			{ 1.0, 0.0 },
			{ 2.0, 1.0 },
			{ 1.0, 2.0 },
			{ 0.0, 1.0 }
		}))
		<< '\n';
}
```
Output:
```
1
```