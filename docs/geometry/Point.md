# `xieite::geometry::Point`
Defined in header [`<xieite/geometry/Point.hpp>`](https://github.com/Eczbek/xieite/tree/main/include/xieite/geometry/Point.hpp)

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
- [`Point`](https://github.com/Eczbek/xieite/tree/main/docs/geometry/Point/constructor.md)
- [`operator==`](https://github.com/Eczbek/xieite/tree/main/docs/geometry/Point/operatorEquals.md)

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
