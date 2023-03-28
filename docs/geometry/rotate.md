# xieite::geometry::rotate
Defined in header `<xieite/geometry/rotate.hpp>`

<br/>

Rotates shapes a specific angle around any pivot.

<br/><br/>

## Declarations
```cpp
[[nodiscard]]
constexpr xieite::geometry::Point rotate(xieite::geometry::Point point, double angle, xieite::geometry::Point pivot = xieite::geometry::Point()) noexcept;
```
```cpp
template<std::derived_from<xieite::geometry::LineLike> LineLike>
[[nodiscard]]
constexpr LineLike rotate(const LineLike& lineLike, double angle, xieite::geometry::Point pivot = xieite::geometry::Point()) noexcept;
```
```cpp
[[nodiscard]]
constexpr xieite::geometry::Polygon rotate(const xieite::geometry::Polygon& polygon, double angle, xieite::geometry::Point pivot = xieite::geometry::Point()) noexcept;
```
```cpp
[[nodiscard]]
constexpr xieite::geometry::Ellipse rotate(const xieite::geometry::Ellipse& ellipse, cdouble angle, xieite::geometry::Point pivot = xieite::geometry::Point()) noexcept;
```
```cpp
[[nodiscard]]
constexpr xieite::geometry::Circle rotate(const xieite::geometry::Circle& circle, double angle, xieite::geometry::Point pivot = xieite::geometry::Point()) noexcept;
```

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
