# [xieite](../xieite.md)::[geometry](../geometry.md)::getSlope
Defined in header [<xieite/geometry/getSlope.hpp>](../../include/xieite/geometry/getSlope.hpp)

<br/>

Calculates the slope of a line or between two points

<br/><br/>

## Synopses

<br/><br/>

```cpp
[[nodiscard]]
constexpr double getSlope(xieite::geometry::Point point1, xieite::geometry::Point point2) noexcept;
```
### Parameters
- `point1` - A `xieite::geometry::Point`
- `point2` - Also a `xieite::geometry::Point`
### Return value
- A `double`, the slope between the passed points, in radians

<br/><br/>

```cpp
template<xieite::concepts::LinearShape LinearShape>
[[nodiscard]]
constexpr double getSlope(const LinearShape& linearShape) noexcept;
```
### Template parameters
- `LinearShape` - A type satisfying `xieite::concepts::LinearShape`
### Parameters
- `linearShape` - A constant `LinearShape` reference
### Return value
- A `double`, the slope of the linear shape, in radians

<br/><br/>

## Example
```cpp
#include <iostream>
#include <xieite/geometry/Line.hpp>
#include <xieite/geometry/getSlope.hpp>

int main() {
	std::cout << xieite::geometry::getSlope(xieite::geometry::Line({ 0.0, 0.0 }, { 2.0, 3.0 })) << '\n';
}
```
Output:
```
1.5
```
