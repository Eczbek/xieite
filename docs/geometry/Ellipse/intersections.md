# gcufl::geometry::Ellipse::intersections
```cpp
std::vector<gcufl::geometry::Point> intersections(const gcufl::geometry::Line& line) const noexcept;

std::vector<gcufl::geometry::Point> intersections(const gcufl::geometry::Ellipse& other) const noexcept;
```
Calculates intersections between the ellipse and a line.
The second version of this function is currently incomplete.
## Example
```cpp
#include <iostream>
#include <gcufl/geometry.hpp>

int main() {
	gcufl::geometry::Ellipse ellipse({ 0, 0 }, { 1, 2 });
	gcufl::geometry::Line line({ 0, 0 }, { 1, 1 });

	for (const gcufl::geometry::Point point: ellipse.intersections(line))
		std::cout << point.x << ' ' << point.y << '\n';
}
```
Output:
```
0.894427 0.894427
-0.894427 -0.894427
```
