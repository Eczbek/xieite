# gcufl::geometry::Polygon::Polygon
```cpp
Polygon(const std::vector<gcufl::geometry::Point>& points) noexcept;
```
Creates a 2D polygon.
## Example
```cpp
#include <iostream>
#include <gcufl/geometry.hpp>

int main() {
	gcufl::geometry::Polygon polygon({
		{ 0, 0 },
		{ 2, 0 },
		{ 2, 2 },
		{ 0, 2 }
	});

	for (const gcufl::geometry::Point point: polygon.points)
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
