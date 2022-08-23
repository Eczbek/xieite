# gcufl::geom::Polygon::sides
```cpp
std::vector<gcufl::geom::Segment> sides() const noexcept;
```
Gets the sides of the polygon.
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

	for (const gcufl::geom::Segment& segment: polygon.sides())
		std::cout
			<< segment.start.x << ", " << segment.start.y << '\n'
			<< segment.end.x << ", " << segment.end.y << '\n';
}
```
Output:
```
0, 0
2, 0
2, 0
2, 2
2, 2
0, 2
0, 2
0, 0
```
