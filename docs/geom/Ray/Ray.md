# gcufl::geom::Ray::Ray
```cpp
Ray(const gcufl::geom::Point start, const gcufl::geom::Point intersection) noexcept;

Ray(const gcufl::geom::Point start, const double angle) noexcept;
```
Creates an infinite 2D ray, extends `gcufl::geom::Line`.
## Example
```cpp
#include <iostream>
#include <gcufl/geom>
#include <gcufl/math>

int main() {
	gcufl::geom::Ray ray1({ 0, 0 }, { 1, 1 });
	gcufl::geom::Ray ray2({ 3, 3 }, gcufl::math::degToRad(45));

	std::cout
		<< ray1.start.x
		<< ", "
		<< ray1.start.y
		<< ", "
		<< ray1.end.x
		<< ", "
		<< ray1.end.y
		<< '\n'
		<< ray2.start.x
		<< ", "
		<< ray2.start.y
		<< ", "
		<< ray2.end.x
		<< ", "
		<< ray2.end.y
		<< '\n';
}
```
Output:
```
0, 0, 1, 1
3, 3, 4, 4
```
