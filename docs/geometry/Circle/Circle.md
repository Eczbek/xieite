# gcufl::geometry::Circle::Circle
```cpp
Circle(const gcufl::geometry::Point center, const double radius) noexcept;
```
Creates a 2D circle, extends `gcufl::geometry::Ellipse`.
## Example
```cpp
#include <gcufl/geometry.hpp>
#include <iostream>

int main() {
	gcufl::geometry::Circle circle({ 0, 0 }, 1);

	std::cout << circle.center.x << ' ' << circle.center.y << '\n'
		<< circle.radius.x << '\n';
}
```
Output:
```
0 0
1
```
