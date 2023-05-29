# [xieite](../../README.md)::[geometry](../geometry.md)::Polygon
Defined in header [<xieite/geometry/Polygon.hpp>](../../include/xieite/geometry/Polygon.hpp)

<br/>

A class representing a polygon

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
### Public members
<pre><code>Polygon/
|- points
|- <a href="./Polygon/constructor.md">Polygon</a>
`- <a href="./Polygon/operatorEquals.md">operator==</a>
</code></pre>

<br/><br/>

## Example
```cpp
#include <iostream>
#include <xieite/geometry/Polygon.hpp>
#include <xieite/geometry/getArea.hpp>

int main() {
	std::cout << xieite::geometry::getArea(xieite::geometry::Polygon({
		{ 1.0, 0.0 },
		{ 2.0, 1.0 },
		{ 1.0, 2.0 },
		{ 0.0, 1.0 }
	})) << '\n';
}
```
Output:
```
1
```
