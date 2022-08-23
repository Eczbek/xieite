# gcufl::geom::Line::slope
```cpp
double slope() const noexcept;
```
Calculates the slope of the line.
## Example
```cpp
#include <iostream>
#include <gcufl/geom>
#include <gcufl/math>

int main() {
	std::cout
		<< gcufl::math::radToDeg(Line({ 0, 0 }, { 1, 1 }).slope())
		<< '\n'
		<< gcufl::math::radToDeg(Line({ 0, 0 }, { 0, 1 }).slope())
		<< '\n'
		<< gcufl::math::radToDeg(Line({ 0, 0 }, { 1, 0 }).slope())
		<< '\n';
}
```
Output:
```
1
inf
0
```
