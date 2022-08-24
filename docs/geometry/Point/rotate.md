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
	gcufl::geometry::Point point1(0, 1);
	gcufl::geometry::Point point2 = Point(1, 0).rotate(gcufl::math::degToRad(90));

	std::cout << (point1 == point2) << '\n';
}
```
Output:
```
true
```
