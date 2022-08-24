# gcufl::geometry::Segment::Segment
```cpp
Segment(const gcufl::geometry::Point start, const gcufl::geometry::Point end) noexcept;
```
Creates a 2D line segment.
## Example
```cpp
#include <iostream>
#include <gcufl/geometry.hpp>

int main() {
	gcufl::geometry::Segment segment({ 0, 0 }, { 2, 2 });

	std::cout
		<< segment.start.x << ", " << segment.start.y << '\n'
		<< segment.end.x << ", " << segment.end.y << '\n';
}
```
Output:
```
0, 0
2, 2
```
