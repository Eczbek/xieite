# gcufl::geometry::Line::slope
```cpp
double slope() const noexcept;
```
Calculates the slope of the line.
## Example
```cpp
#include <iostream>
#include <gcufl/geometry.hpp>
#include <gcufl/math.hpp>

int main() {
	gcufl::geometry::Line line1({ 0, 0 }, { 1, 1 });
	gcufl::geometry::Line line2({ 0, 0 }, { 0, 1 });
	gcufl::geometry::Line line3({ 0, 0 }, { 1, 0 });

	std::cout
		<< gcufl::math::radToDeg(line1.slope())
		<< '\n'
		<< gcufl::math::radToDeg(line2.slope())
		<< '\n'
		<< gcufl::math::radToDeg(line3.slope())
		<< '\n';
}
```
Output:
```
1
inf
0
```
