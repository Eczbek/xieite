# gcufl::geom::Segment::Segment
```cpp
Segment(const gcufl::geom::Point start, const gcufl::geom::Point end) noexcept;
```
Creates a 2D line segment.
## Example
```cpp
#include <iostream>
#include <gcufl/geom>

int main() {
	gcufl::geom::Segment segment({ 0, 0 }, { 2, 2 });

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
