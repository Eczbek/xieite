# gcufl::geom::Polygon::Polygon
```cpp
Polygon(const std::vector<gcufl::geom::Point>& points) noexcept;
```
Creates a 2D polygon.
## Example
```cpp
#include <iostream>
#include <gcufl/geom>

int main() {
	gcufl::geom::Polygon polygon({
		{ 0, 0 },
		{ 2, 0 },
		{ 2, 2 },
		{ 0, 2 }
	});

	for (const gcufl::geom::Point point: polygon.points)
		std::cout << point.x << ", " << point.y << '\n';
}
```
Output:
```
0, 0
2, 0
2, 2
0, 2
```
