# [`xieite`](../../README.md)`::`[`geometry`](../../docs/geometry.md)`::Ray`
Defined in header [`<xieite/geometry/Ray.hpp>`](../../include/xieite/geometry/Ray.hpp)

<br/>

A struct representing an infinite ray with one end.

<br/><br/>

## Synopsis

<br/>

```cpp
struct Ray final {
	xieite::geometry::Point start;
	xieite::geometry::Point end;

	constexpr Ray(xieite::geometry::Point, xieite::geometry::Point);

	constexpr Ray(xieite::geometry::Point, double);

	constexpr bool operator==(const xieite::geometry::Ray&) const;
};
```
### Member objects
- `start` - A `xieite::geometry::Point`
- `end` - Another `xieite::geometry::Point`
### Member functions
- [`Ray`](../../docs/geometry/Ray/constructor.md)
- [`operator==`](../../docs/geometry/Ray/operatorEquals.md)

<br/><br/>

## Example
```cpp
#include <iostream>
#include <xieite/geometry/Ray.hpp>

int main() {
	std::cout
		<< std::boolalpha
		<< xieite::geometry::containsPoint(xieite::geometry::Ray({ 0.0, 0.0 }, { 1.0, 1.0 }), { -1.0, -1.0 })
		<< '\n';
}
```
Output:
```
false
```

<br/><br/>

## See also
- [`xieite::geometry::Point`](../../docs/geometry/Point.md)
