# xieite::geometry::containsPoint
Declared in `<xieite/geometry/containsPoint.hpp>`

<br/>

Checks whether a shape or line contains a point.

<br/><br/>

## Declarations
```cpp
[[nodiscard]]
constexpr bool containsPoint(const xieite::geometry::Point point1, const xieite::geometry::Point point2) noexcept;
```
```cpp
[[nodiscard]]
constexpr bool containsPoint(const xieite::geometry::Line& line, const xieite::geometry::Point point) noexcept;
```
```cpp
[[nodiscard]]
constexpr bool containsPoint(const xieite::geometry::Ray& ray, const xieite::geometry::Point point) noexcept;
```
```cpp
[[nodiscard]]
constexpr bool containsPoint(const xieite::geometry::Segment& segment, const xieite::geometry::Point point) noexcept;
```
```cpp
[[nodiscard]]
constexpr bool containsPoint(const xieite::geometry::Polygon& polygon, const xieite::geometry::Point point) noexcept;
```
```cpp
[[nodiscard]]
constexpr bool containsPoint(const xieite::geometry::Ellipse& ellipse, const xieite::geometry::Point point) noexcept;
```
```cpp
[[nodiscard]]
constexpr bool containsPoint(const xieite::geometry::Circle& circle, const xieite::geometry::Point point) noexcept;
```

<br/><br/>

## Example
```cpp
#include <iostream>
#include <xieite/geometry/Polygon.hpp>
#include <xieite/geometry/containsPoint.hpp>

int main() {
	const xieite::geometry::Polygon square({
		{ -1, -1 },
		{ 1, -1 },
		{ 1, 1 },
		{ -1, 1 }
	});

	std::cout << std::boolalpha
		<< xieite::geometry::containsPoint(square, { 0, 0 }) << '\n';
}
```
Output:
```
true
```
