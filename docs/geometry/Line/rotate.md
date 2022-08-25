# gcufl::geometry::Line::rotate
```cpp
gcufl::geometry::Line rotate(const double angle, const gcufl::geometry::Point pivot = gcufl::geometry::Point(0, 0));
```
Rotates a copy of the line about a pivot.
## Example
```cpp
#include <iostream>
#include <gcufl/geometry.hpp>
#include <gcufl/math.hpp>

int main() {
	gcufl::geometry::Line line1({ 0, 0 }, { 1, 1 });
	gcufl::geometry::Line line2 = line1.rotate(gcufl::math::degToRad(90));

	std::cout << line2.slope() << '\n';
}
```
Output:
```
-1
```
