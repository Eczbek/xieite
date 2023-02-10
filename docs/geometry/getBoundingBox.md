# xieite::geometry::getBoundingBox
Declared in `<xieite/geometry/getBoundingBox.hpp>`

<br/>

Creates a minimal rectangle to contain an ellipse or circle.

<br/><br/>

## Declarations
```cpp
[[nodiscard]]
constexpr xieite::geometry::Polygon getBoundingBox(const xieite::geometry::Ellipse& ellipse) noexcept;
```
```cpp
[[nodiscard]]
constexpr xieite::geometry::Polygon getBoundingBox(const xieite::geometry::Circle& circle) noexcept;
```

<br/><br/>

## Example
```cpp
#include <iostream> // std::cout
#include <xieite/geometry/Circle.hpp>
#include <xieite/geometry/Point.hpp>
#include <xieite/geometry/getBoundingBox.hpp>

int main() {
	xieite::geometry::Circle circle({ 0, 0 }, 1);
	for (const xieite::geometry::Point point : xieite::geometry::getBoundingBox(circle).points)
		std::cout << point.x << ' ' << point.y << '\n';
}
```
Output:
```
-1 -1
1 -1
1 1
-1 1
```
