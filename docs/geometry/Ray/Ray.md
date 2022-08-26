# gcufl::geometry::Ray::Ray
```cpp
Ray(const gcufl::geometry::Point start, const gcufl::geometry::Point intersection) noexcept;

Ray(const gcufl::geometry::Point start, const double angle) noexcept;
```
Creates an infinite 2D ray, extends `gcufl::geometry::Line`.
## Example
```cpp
#include <iostream>
#include <gcufl/geometry.hpp>
#include <gcufl/math.hpp>

int main() {
	gcufl::geometry::Ray ray1({ 0, 0 }, { 1, 1 });
	gcufl::geometry::Ray ray2({ 3, 3 }, gcufl::math::radians(45));

	std::cout
		<< ray1.start.x << ' ' << ray1.start.y << '\n'
		<< ray1.end.x << ' ' << ray1.end.y << "\n\n"
		<< ray2.start.x << ' ' << ray2.start.y << '\n'
		<< ray2.end.x << ' ' << ray2.end.y << '\n';
}
```
Output:
```
0 0
1 1

3 3
4 4
```
