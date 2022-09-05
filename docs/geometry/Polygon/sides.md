# gcufl::geometry::Polygon::sides
```cpp
std::vector<gcufl::geometry::Segment> sides() const noexcept;
```
Gets the sides of a polygon.
## Example
```cpp
#include <gcufl/geometry.hpp>
#include <iostream>

int main() {
	for (const gcufl::geometry::Segment& segment : gcufl::geometry::Polygon({
		{ 0, 0 },
		{ 2, 0 },
		{ 2, 2 },
		{ 0, 2 }
	}).sides())
		std::cout << segment.start.x << ' ' << segment.start.y << '\n'
			<< segment.end.x << ' ' << segment.end.y << "\n\n;
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
