# `xieite::geometry::Ellipse`
Defined in header [`<xieite/geometry/Ellipse.hpp>`](../../include/xieite/geometry/Ellipse.hpp)

<br/>

An struct representing an ellipse.

<br/><br/>

## Synopsis

<br/>

### Member objects
```cpp
xieite::geometry::Point center;
```
```cpp
xieite::geometry::Point radii;
```
```cpp
double rotation;
```

<br/>

### Member functions
- [`Ellipse`](../../docs/geometry/Ellipse/constructor.md)
- [`operator==`](../../docs/geometry/Ellipse/operatorEquals.md)

<br/><br/>

## Example
```cpp
#include <iostream>
#include <xieite/geometry/Ellipse.hpp>
#include <xieite/geometry/getArea.hpp>

int main() {
	std::cout << xieite::geometry::getArea(xieite::geometry::Ellipse({ 0.0, 0.0 }, { 1.0, 2.0 })) << '\n';
}
```
Output:
```
6.28319
```

<br/><br/>

## See also
- [`xieite::geometry::Point`](../../docs/geometry/Point.md)
