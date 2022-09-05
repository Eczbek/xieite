# gcufl::geometry::Polygon::Polygon
```cpp
Polygon(const std::vector<gcufl::geometry::Point>& points) noexcept;
```
Creates a 2D polygon.
## Example
```cpp
#include <gcufl/geometry.hpp>
#include <iostream>

int main() {
	for (const gcufl::geometry::Point point : gcufl::geometry::Polygon({
		{ 0, 0 },
		{ 2, 0 },
		{ 2, 2 },
		{ 0, 2 }
	}).points)
		std::cout << point.x << ' ' << point.y << '\n';
}
```
Output:
```
0 0
2 0
2 2
0 2
```
