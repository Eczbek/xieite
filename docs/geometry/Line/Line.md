# gcufl::geometry::Line::Line
```cpp
Line(const gcufl::geometry::Point intersection1, const gcufl::geometry::Point intersection2) noexcept;

Line(const gcufl::geometry::Point intersection, const double angle) noexcept;
```
Creates an infinite 2D line.
## Example
```cpp
#include <iostream>
#include <gcufl/geometry.hpp>
#include <gcufl/math.hpp>

int main() {
	gcufl::geometry::Line line1({ 0, 0 }, { 1, 1 });
	gcufl::geometry::Line line2({ 3, 3 }, gcufl::math::degToRad(45));

	std::cout
		<< line1.start.x << ", " << line1.start.y << '\n'
		<< line1.end.x << ", " << line1.end.y << '\n'
		<< line2.start.x << ", " << line2.start.y << '\n'
		<< line2.end.x << ", " << line2.end.y << '\n';
}
```
Output:
```
0, 0
1, 1
3, 3
4, 4
```
