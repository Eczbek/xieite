# gcufl::geometry::Circle::rotate
```cpp
gcufl::geometry::Circle rotate(const double angle, const gcufl::geometry::Point pivot = gcufl::geometry::Point(0, 0)) const noexcept;
```
Rotates a copy of the circle about a pivot.
## Example
```cpp
#include <iostream>
#include <gcufl/geometry.hpp>
#include <gcufl/math.hpp>

int main() {
	gcufl::geometry::Circle circle1({ 1, 0 }, 1);
	gcufl::geometry::Circle circle2 = circle1.rotate(gcufl::math::degToRad(90));
	
	std::cout << circle2.center.x << ' ' circle2.center.y << '\n';
}
```
Output:
```
0 1
```
