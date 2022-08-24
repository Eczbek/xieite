# gcufl::geometry::Line::angle
```cpp
double angle() const noexcept;
```
Calculates the angle of the line.
## Example
```cpp
#include <iostream>
#include <gcufl/geometry.hpp>
#include <gcufl/math.hpp>

int main() {
	std::cout
		<< gcufl::math::radToDeg(gcufl::geometry::Line({ 0, 0 }, { 1, 1 }))
		<< '\n'
		<< gcufl::math::radToDeg(gcufl::geometry::Line({ 0, 0 }, { 0, 1 }))
		<< '\n'
		<< gcufl::math::radToDeg(gcufl::geometry::Line({ 0, 0 }, { 1, 0 }))
		<< '\n';
}
```
Output:
```
45
90
0
```
