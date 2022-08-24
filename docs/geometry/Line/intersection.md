# gcufl::geometry::Line::intersection
```cpp
std::optional<gcufl::geometry::Point> intersection(const gcufl::geometry::Line& other) const noexcept;
```
Calculates a possible intersection between two lines. Handles derived classes `gcufl::geometry::Ray` and `gcufl::geometry::Segment`.
## Example
```cpp
#include <iostream>
#include <gcufl/geometry.hpp>

int main() {
	gcufl::geometry::Line line1({ 0, 0 }, { 1, 1 });
	gcufl::geometry::Line line2({ 0, 2 }, { 1, -1 });

	gcufl::geometry::Point point = line1.intersection(line2).value_or({ 0, 0 });

	std::cout << point.x << ' ' << point.y << '\n';
}
```
Output:
```
1 1
```
