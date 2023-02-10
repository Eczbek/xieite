# xieite::geometry::rotate
Declared in `<xieite/geometry/rotate.hpp>`

<br/>

Rotates shapes.

<br/><br/>

## Declarations
```cpp
[[nodiscard]]
constexpr xieite::geometry::Point rotate(const xieite::geometry::Point& point, const long double angle, const xieite::geometry::Point& pivot = xieite::geometry::Point(0, 0)) noexcept;
```
```cpp
template<std::derived_from<xieite::geometry::AbstractLine> LineLike>
[[nodiscard]]
constexpr LineLike rotate(const LineLike& lineLike, const long double angle, const xieite::geometry::Point& pivot = xieite::geometry::Point(0, 0)) noexcept;
```
```cpp
[[nodiscard]]
constexpr xieite::geometry::Polygon rotate(const xieite::geometry::Polygon& polygon, const long double angle, const xieite::geometry::Point& pivot = xieite::geometry::Point(0, 0)) noexcept;
```
```cpp
[[nodiscard]]
constexpr xieite::geometry::Ellipse rotate(const xieite::geometry::Ellipse& ellipse, const long double angle, const xieite::geometry::Point& pivot = xieite::geometry::Point(0, 0)) noexcept;
```

<br/><br/>

## Example
```cpp
#include <iostream> // std::cout
#include <xieite/geometry/Line.hpp>
#include <xieite/geometry/getSlope.hpp>
#include <xieite/geometry/rotate.hpp>
#include <xieite/math/toRadians.hpp>

int main() {
	const xieite::geometry::Line line1({ 0, 0 }, { 1, 1 });
	const long double angle = xieite::math::toRadians<long double>(90);
	const xieite::geometry::Line line2 = xieite::geometry::rotate(line1, angle);
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
