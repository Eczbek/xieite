# gcufl::geometry::Ellipse::boundingBox
```cpp
gcufl::geometry::Polygon boundingBox() const noexcept;
```
Creates a bounding box of the ellipse.
## Example
```cpp
#include <iostream>
#include <gcufl/geometry.hpp>

int main() {
	gcufl::geometry::Ellipse ellipse({ 0, 0 }, { 1, 2 });
	
	for (const gcufl::geometry::Point point: ellipse.boundingBox().points)
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
