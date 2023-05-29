# [xieite](../../README.md)::[geometry](../geometry.md)::Point
Defined in header [<xieite/geometry/Point.hpp>](../../include/xieite/geometry/Point.hpp)

<br/>

A class representing a point

<br/><br/>

## Synopsis

<br/>

```cpp
struct Point final {
	double x;
	double y;

	constexpr Point(double = 0.0, double = 0.0);

	constexpr bool operator==(xieite::geometry::Point) const;
};
```
### Public members
<pre><code>Point/
|- x
|- y
|- <a href="./Point/constructor.md">Point</a>
`- <a href="./Point/operatorEquals.md">operator==</a>
</code></pre>

<br/><br/>

## Example
```cpp
#include <iostream>
#include <xieite/geometry/Point.hpp>
#include <xieite/geometry/getRotated.hpp>
#include <xieite/math/toRadians.hpp>

int main() {
	xieite::geometry::Point point = xieite::geometry::getRotated({ 1.0, 0.0 }, xieite::math::toRadians(90.0));
	
	std::cout << '(' << point.x << ", " << point.y << ")\n";
}
```
Output (rounded):
```
(0, 1)
```
