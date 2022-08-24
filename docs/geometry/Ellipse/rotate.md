# gcufl::geometry::Ellipse::rotate
```cpp
gcufl::geometry::Ellipse rotate(const double angle, const gcufl::geometry::Point pivot = gcufl::geometry::Point(0, 0)) const noexcept;
```
Rotates a copy of the ellipse about a pivot.
## Example
```cpp
#include <iostream>
#include <gcufl/geometry.hpp>
#include <gcufl/math.hpp>

int main() {
	gcufl::geometry::Ellipse ellipse1({ 0, 0 }, { 1, 2 });
	gcufl::geometry::Ellipse ellipse2 = ellipse1.rotate(gcufl::math::degToRad(90));
	
	for (const gcufl::geometry::Point point: ellipse2.boundingBox().points)
		std::cout << point.x << ", " << point.y << '\n';
}
```
Output:
```
-2, -1
2, -1
2, 1
-2, 1
```
