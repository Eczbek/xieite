# gcufl::geometry::Line::interceptY
```cpp
double interceptY() const noexcept;
```
Calculates the y-intercept of the line.
## Example
```cpp
#include <gcufl/geometry.hpp>
#include <iostream>

int main() {
	gcufl::geometry::Line line({ 1, 2 }, { 1, -1 })

	std::cout << line.interceptY() << '\n';
}
```
Output:
```
3
```
