# gcufl::geom::Line::Line
```cpp
Line(const gcufl::geom::Point intersection1, const gcufl::geom::Point intersection2) noexcept;

Line(const gcufl::geom::Point intersection, const double angle) noexcept;
```
Creates an infinite 2D line.
## Example
```cpp
#include <iostream>
#include <gcufl/geom>
#include <gcufl/math>

int main() {
	gcufl::geom::Line line1({ 0, 0 }, { 1, 1 });
	gcufl::geom::Line line2({ 3, 3 }, gcufl::math::degToRad(45));

	std::cout
		<< line1.start.x
		<< ", "
		<< line1.start.y
		<< ", "
		<< line1.end.x
		<< ", "
		<< line1.end.y
		<< '\n'
		<< line2.start.x
		<< ", "
		<< line2.start.y
		<< ", "
		<< line2.end.x
		<< ", "
		<< line2.end.y
		<< '\n';
}
```
Output:
```
0, 0, 1, 1
3, 3, 4, 4
```
