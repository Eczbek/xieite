# [xieite](../xieite.md)::[geometry](../geometry.md)::getAxisIntercept
Defined in header [<xieite/geometry/getAxisIntercept.hpp>](../../include/xieite/geometry/getAxisIntercept.hpp)

<br/>

Finds a point where a line intercepts an axis of origin

<br/><br/>

## Synopsis

<br/>

```cpp
template<xieite::concepts::LinearShape LinearShape>
[[nodiscard]]
constexpr xieite::geometry::Point getAxisIntercept(const LinearShape& linearShape, const xieite::geometry::Point origin = xieite::geometry::Point(0.0, 0.0)) noexcept;
```
### Template parameters
- `LinearShape` - A type satisfying `xieite::concepts::LinearShape`
### Parameters
- `linearShape` - A constant `LinearShape` reference
- `origin` - A `xieite::geometry::Point`, set to `xieite::geometry::Point(0.0, 0.0)` by default
### Return value
- A `xieite::geometry::Point`, the intercept point

<br/><br/>

## Example
```cpp
#include <iostream>
#include <xieite/geometry/Line.hpp>
#include <xieite/geometry/Point.hpp>
#include <xieite/geometry/getAxisIntercept.hpp>

int main() {
	xieite::geometry::Point start(1.0, 2.0);
	xieite::geometry::Point end(2.0, 1.0);

	xieite::geometry::Line line(start, end);

	xieite::geometry::Point intercept = xieite::geometry::getAxisIntercept(line);

	std::cout << '(' << intercept.x << ", " << intercept.y << ")\n";
}
```
Output:
```
(3, 0)
```
