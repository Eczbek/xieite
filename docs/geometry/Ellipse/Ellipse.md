# gcufl::geometry::Ellipse::Ellipse
```cpp
Ellipse(const gcufl::geometry::Point center, const gcufl::geometry::Point radius, const double rotation = 0) noexcept;
```
Creates a 2D ellipse.
## Example
```cpp
#include <iostream>
#include <gcufl/geometry.hpp>

int main() {
	gcufl::geometry::Ellipse ellipse({ 0, 0 }, { 1, 2 });

	std::cout
		<< ellipse.center.x << ' ' << ellipse.center.y << '\n'
		<< ellipse.radius.x << ' ' << ellipse.radius.y << '\n';
}
```
Output:
```
0 0
1 2
```
