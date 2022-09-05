# gcufl::geometry::Ellipse::boundingBox
```cpp
gcufl::geometry::Polygon boundingBox() const noexcept;
```
Creates a bounding box of an ellipse.
## Example
```cpp
#include <gcufl/geometry.hpp>
#include <iostream>

int main() {
	for (const gcufl::geometry::Point point : gcufl::geometry::Ellipse({ 0, 0 }, { 1, 2 }).boundingBox().points)
		std::cout << point.x << ' ' << point.y << '\n';
}
```
Output:
```
-1 -2
1 -2
1 2
-1 2
```
