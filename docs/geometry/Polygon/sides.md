# gcufl::geometry::Polygon::sides
```cpp
std::vector<gcufl::geometry::Segment> sides() const noexcept;
```
Gets the sides of the polygon.
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

	for (const gcufl::geometry::Segment& segment: polygon.sides())
		std::cout
			<< segment.start.x << ' ' << segment.start.y << '\n'
			<< segment.end.x << ' ' << segment.end.y << '\n';
}
```
Output:
```
0 0
2 0
2 0
2 2
2 2
0 2
0 2
0 0
```
