# gcufl::geom::Line::intersection
```cpp
std::optional<gcufl::geom::Point> intersection(const gcufl::geom::Line& other) const noexcept;
```
Calculates a possible intersection between two lines. Handles derived classes `gcufl::geom::Ray` and `gcufl::geom::Segment`.
## Example
```cpp
#include <iostream>
#include <gcufl/geom>

int main() {
	gcufl::geom::Line line1({ 0, 0 }, { 1, 1 });
	gcufl::geom::Line line2({ 0, 2 }, { 1, -1 });

	gcufl::geom::Point point = line1.intersection(line2).value_or({ 0, 0 });

	std::cout << point.x << ", " << point.y << '\n';
}
```
Output:
```
1, 1
```
