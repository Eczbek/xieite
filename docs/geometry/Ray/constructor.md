# [`xieite`](../../../README.md)`::`[`geometry`](../../../docs/geometry.md)`::`[`Ray`](../../../docs/geoemtry/Ray.md)`::Ray`
Defined in header [`<xieite/geometry/Ray.hpp>`](../../../include/xieite/geometry/Ray.hpp)

<br/>

Constructs a `xieite::geometry::Ray`.

<br/><br/>

## Synopsis

<br/>

```cpp
constexpr Ray(xieite::geometry::Point start, xieite::geometry::Point end) noexcept;
```
### Parameters
- `start` - A `xieite::geometry::Point` copy, the start of the ray
- `end` - A `xieite::geometry::Point` copy, an intersection through which the infinite ray passes

<br/><br/>

```cpp
constexpr Ray(xieite::geometry::Point start, double angle) noexcept;
```
### Parameters
- `start` - A `xieite::geometry::Point` copy, the start of the ray
- `angle` - A `double` copy, the ray's angle

<br/><br/>

## Example
```cpp
#include <iostream>
#include <xieite/geometry/Ray.hpp>
#include <xieite/geometry/Point.hpp>
#include <xieite/geometry/containsPoint.hpp>

int main() {
	xieite::geometry::Point start(0.0, 0.0);
	xieite::geometry::Point end(1.0, 1.0);
	xieite::geometry::Point point(-1.0, -1.0);

	xieite::geometry::Ray ray(stat, end);

	std::cout
		<< std::boolalpha
		<< xieite::geometry::containsPoint(ray, point)
		<< '\n';
}
```
Output:
```
false
```