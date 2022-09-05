# gcufl::geometry::Line::interceptX
```cpp
double interceptX() const noexcept;
```
Calculates the x-intercept of the line.
## Example
```cpp
#include <gcufl/geometry.hpp>
#include <iostream>

int main() {
	gcufl::geometry::Line line({ 1, 2 }, { 1, -1 })

	std::cout << line.interceptX() << '\n';
}
```
Output:
```
3
```
