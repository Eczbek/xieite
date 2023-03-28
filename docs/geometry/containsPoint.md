# xieite::geometry::containsPoint
Defined in header `<xieite/geometry/containsPoint.hpp>`

<br/>

Checks whether a shape or line contains a point.

<br/><br/>

## Declarations
```cpp
[[nodiscard]]
constexpr bool containsPoint(xieite::geometry::Point point1, xieite::geometry::Point point2) noexcept;
```
```cpp
[[nodiscard]]
constexpr bool containsPoint(const xieite::geometry::Line& line, xieite::geometry::Point point) noexcept;
```
```cpp
[[nodiscard]]
constexpr bool containsPoint(const xieite::geometry::Ray& ray, xieite::geometry::Point point) noexcept;
```
```cpp
[[nodiscard]]
constexpr bool containsPoint(const xieite::geometry::Segment& segment, xieite::geometry::Point point) noexcept;
```
```cpp
[[nodiscard]]
constexpr bool containsPoint(const xieite::geometry::Polygon& polygon, xieite::geometry::Point point) noexcept;
```
```cpp
[[nodiscard]]
constexpr bool containsPoint(const xieite::geometry::Ellipse& ellipse, xieite::geometry::Point point) noexcept;
```
```cpp
[[nodiscard]]
constexpr bool containsPoint(const xieite::geometry::Circle& circle, xieite::geometry::Point point) noexcept;
```

<br/><br/>

## Example
```cpp
#include <iostream>
#include <xieite/geometry/Polygon.hpp>
#include <xieite/geometry/containsPoint.hpp>

int main() {
	xieite::geometry::Polygon square({
		{ -1.0, -1.0 },
		{ 1.0, -1.0 },
		{ 1.0, 1.0 },
		{ -1.0, 1.0 }
	});

	std::cout << std::boolalpha
		<< xieite::geometry::containsPoint(square, { 0.0, 0.0 }) << '\n';
}
```
Output:
```
true
```
