# gcufl::geom::Polygon::rotate
```cpp
gcufl::geom::Polygon rotate(const double angle, const gcufl::geom::Point pivot = gcufl::geom::Point(0, 0)) const noexcept;
```
Rotates a copy of the polygon about a pivot.
## Example
```cpp
#include <iostream>
#include <gcufl/geom>
#include <gcufl/math>

int main() {
	gcufl::geom::Polygon polygon({
		{ 0, 0 },
		{ 2, 0 },
		{ 2, 2 },
		{ 0, 2 }
	});

	for (const gcufl::geom::Point point: polygon.rotate(gcufl::math::degToRad(90)).points)
		std::cout << point.x << ", " << point.y << '\n';
}
```
Output:
```
0, 0
0, 2
-2, 2
-2, 0
```
