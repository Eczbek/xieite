# gcufl::geometry::Polygon::rotate
```cpp
gcufl::geometry::Polygon rotate(const double angle, const gcufl::geometry::Point pivot = gcufl::geometry::Point(0, 0)) const noexcept;
```
Rotates a copy of the polygon about a pivot.
## Example
```cpp
#include <iostream>
#include <gcufl/geometry.hpp>
#include <gcufl/math.hpp>

int main() {
	gcufl::geometry::Polygon polygon({
		{ 0, 0 },
		{ 2, 0 },
		{ 2, 2 },
		{ 0, 2 }
	});

	for (const gcufl::geometry::Point point : polygon.rotate(gcufl::math::degToRad(90)).points)
		std::cout << point.x << ' ' << point.y << '\n';
}
```
Output:
```
0 0
0 2
-2 2
-2 0
```
