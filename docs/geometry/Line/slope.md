# gcufl::geometry::Line::slope
```cpp
double slope() const noexcept;
```
Calculates the slope of a line.
## Example
```cpp
#include <gcufl/geometry.hpp>
#include <iostream>

int main() {
	gcufl::geometry::Line line1({ 0, 0 }, { 1, 1 });
	gcufl::geometry::Line line2({ 0, 0 }, { 0, 1 });
	gcufl::geometry::Line line3({ 0, 0 }, { 1, 0 });

	std::cout << line1.slope() << '\n'
		<< line2.slope() << '\n'
		<< line3.slope() << '\n';
}
```
Output:
```
1
inf
0
```
