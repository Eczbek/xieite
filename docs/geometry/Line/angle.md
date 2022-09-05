# gcufl::geometry::Line::angle
```cpp
double angle() const noexcept;
```
Calculates the angle of the line.
## Example
```cpp
#include <gcufl/geometry.hpp>
#include <gcufl/math.hpp>
#include <iostream>

int main() {
	gcufl::geometry::Line line1({ 0, 0 }, { 1, 1 });
	gcufl::geometry::Line line2({ 0, 0 }, { 0, 1 });
	gcufl::geometry::Line line3({ 0, 0 }, { 1, 0 });

	std::cout
		<< gcufl::math::degrees(line1) << '\n'
		<< gcufl::math::degrees(line2) << '\n'
		<< gcufl::math::degrees(line3) << '\n';
}
```
Output:
```
45
90
0
```
