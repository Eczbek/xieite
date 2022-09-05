# gcufl::geometry::Line::rotate
```cpp
gcufl::geometry::Line rotate(const double angle, const gcufl::geometry::Point pivot = gcufl::geometry::Point(0, 0));
```
Rotates a copy of a line about a pivot.
## Example
```cpp
#include <gcufl/geometry.hpp>
#include <gcufl/math.hpp>
#include <iostream>

int main() {
	gcufl::geometry::Line line1({ 0, 0 }, { 1, 1 });
	gcufl::geometry::Line line2 = line1.rotate(gcufl::math::radians(90));

	std::cout << line2.slope() << '\n';
}
```
Output:
```
-1
```
