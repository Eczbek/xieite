# [`xieite`](../../README.md)`::`[`geometry`](../../docs/geometry.md)`::Point`
Defined in header [`<xieite/geometry/Point.hpp>`](../../include/xieite/geometry/Point.hpp)

<br/>

A struct representing a point.

<br/><br/>

## Synopsis

<br/>

### Member objects
```cpp
double x;
```
```cpp
double y;
```

<br/>

### Member functions
- [`Point`](../../docs/geometry/Point/constructor.md)
- [`operator==`](../../docs/geometry/Point/operatorEquals.md)

<br/><br/>

## Example
```cpp
#include <iostream>
#include <xieite/geometry/Point.hpp>
#include <xieite/geometry/rotate.hpp>
#include <xieite/math/toRadians.hpp>

int main() {
	xieite::geometry::Point point = xieite::geometry::rotate({ 1.0, 0.0 }, xieite::math::toRadians(90.0));
	
	std::cout << '(' << point.x << ", " << point.y << ")\n";
}
```
Output (rounded):
```
(0, 1)
```
