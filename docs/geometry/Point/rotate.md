# gcufl::geometry::Point::rotate
```cpp
gcufl::geometry::Point rotate(const double angle, const gcufl::geometry::Point pivot = gcufl::geometry::Point(0, 0)) const noexcept;
```
Rotates a copy of this point about a pivot.
## Example
```cpp
#include <iostream>
#include <gcufl/geometry.hpp>
#include <gcufl/math.hpp>

int main() {
	gcufl::geometry::Point point1(1, 0);
	gcufl::geometry::Point point2 = point1.rotate(gcufl::math::degToRad(90));

	std::cout << point2.x << ' ' << point2.y << '\n';
}
```
Output:
```
0 1
```
