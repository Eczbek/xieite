# gcufl::geometry::Polygon::rotate
```cpp
gcufl::geometry::Polygon rotate(const double angle, const gcufl::geometry::Point pivot = gcufl::geometry::Point(0, 0)) const noexcept;
```
Rotates a copy of a polygon about a pivot.
## Example
```cpp
#include <gcufl/geometry.hpp>
#include <gcufl/math.hpp>
#include <iostream>

int main() {
	for (const gcufl::geometry::Point point : gcufl::geometry::Polygon({
		{ 0, 0 },
		{ 2, 0 },
		{ 2, 2 },
		{ 0, 2 }
	}).rotate(gcufl::math::radians(90)).points)
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
