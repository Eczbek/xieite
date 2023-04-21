# [`xieite`](../../../README.md)`::`[`geometry`](../../../docs/geometry.md)`::`[`Circle`](../../../docs/geometry/Circle.md)`::Circle`
Defined in header [`<xieite/geometry/Circle.hpp>`](../../../include/xieite/geometry/Circle.hpp)

<br/>

Constructs a `xieite::geometry::Circle`.

<br/><br/>

## Synopsis

<br/>

```cpp
constexpr Circle(xieite::geometry::Point center, double radius) noexcept;
```
### Parameters
- `center` - A `xieite::geometry::Point` copy, determining the center of the constructed circle
- `radius` - A `double` copy for the circle's radius

<br/><br/>

## Example
```cpp
#include <iostream>
#include <xieite/geometry/Circle.hpp>
#include <xieite/geometry/Point.hpp>
#include <xieite/geometry/getArea.hpp>

int main() {
	xieite::geometry::Point center(0.0, 0.0);

	xieite::geometry::Circle circle(center, 3.0);

	std::cout << xieite::geometry::getArea(circle) << '\n';
}
```
Output:
```
28.2743
```

<br/><br/>

## See also
- [`xieite::geometry::Point`](../../../docs/geometry/Point.md)
