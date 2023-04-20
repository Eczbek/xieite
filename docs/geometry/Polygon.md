# `xieite::geometry::Polygon`
Defined in header [`<xieite/geometry/Polygon.hpp>`](https://github.com/Eczbek/xieite/tree/main/include/xieite/geometry/Polygon.hpp)

<br/>

A struct representing a polygon.

<br/><br/>

## Synopsis

<br/>

### Member objects
```cpp
std::vector<xieite::geometry::Point> points;
```

<br/>

### Member functions
- [`Polygon`](https://github.com/Eczbek/xieite/tree/main/docs/geometry/Polygon/constructor.md)
- [`operator==`](https://github.com/Eczbek/xieite/tree/main/docs/geometry/Polygon/operatorEquals.md)

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

<br/><br/>

## See also
- [`xieite::geometry::Point`](https://github.com/Eczbek/xieite/tree/main/docs/geometry/Point.md)
