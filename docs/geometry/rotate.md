# [xieite](../../README.md)::[geometry](../geometry.md)::rotate
Defined in header [<xieite/geometry/rotate.hpp>](../../include/xieite/geometry/rotate.hpp)

<br/>

Rotates shapes a specific angle around any pivot, clockwise

<br/><br/>

## Synopses

<br/><br/>

```cpp
[[nodiscard]]
constexpr xieite::geometry::Point rotate(xieite::geometry::Point point, double angle, xieite::geometry::Point pivot = xieite::geometry::Point(0, 0)) noexcept;
```
### Parameters
- `point` - A `xieite::geometry::Point` copy
- `angle` - A `double` copy, clockwise rotation in radians
- `pivot` - A `xieite::geometry::Point` copy, is `{ 0, 0 }` by default
### Return value
- A new rotated `xieite::geometry::Point`

<br/><br/>

```cpp
template<xieite::concepts::LinearShape LinearShape>
[[nodiscard]]
constexpr LinearShape rotate(const LinearShape& linearShape, double angle, xieite::geometry::Point pivot = xieite::geometry::Point(0, 0)) noexcept;
```
### Template parameters
- `LinearShape` - The type of the passed linear shape, satisfying `xieite::concepts::LinearShape`
### Parameters
- `linearShape` - A `LinearShape` constant reference
- `angle` - A `double` copy, clockwise rotation in radians
- `pivot` - A `xieite::geometry::Point` copy, is `{ 0, 0 }` by default
### Return value
- A new rotated `LinearShape`

<br/><br/>

```cpp
[[nodiscard]]
constexpr xieite::geometry::Polygon rotate(const xieite::geometry::Polygon& polygon, double angle, xieite::geometry::Point pivot = xieite::geometry::Point(0, 0)) noexcept;
```
### Parameters
- `linearShape` - A `xieite::geometry::Polygon` constant reference
- `angle` - A `double` copy, clockwise rotation in radians
- `pivot` - A `xieite::geometry::Point` copy, is `{ 0, 0 }` by default
### Return value
- A new rotated `xieite::geometry::Polygon`

<br/><br/>

## Example
```cpp
#include <iostream>
#include <xieite/geometry/Line.hpp>
#include <xieite/geometry/getSlope.hpp>
#include <xieite/geometry/rotate.hpp>
#include <xieite/math/toRadians.hpp>

int main() {
	xieite::geometry::Line line1({ 0, 0 }, { 1, 1 });

	xieite::geometry::Line line2 = xieite::geometry::rotate(line1, xieite::math::toRadians(90.0));

	std::cout
		<< xieite::geometry::getSlope(line1) << '\n'
		<< xieite::geometry::getSlope(line2) << '\n';
}
```
Output:
```
1
-1
```
