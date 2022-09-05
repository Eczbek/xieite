# gcufl::geometry::Line::interceptX
```cpp
double interceptX() const noexcept;
```
Calculates the x-intercept of a line.
## Example
```cpp
#include <gcufl/geometry.hpp>
#include <iostream>

int main() {
	std::cout << gcufl::geometry::Line({ 1, 2 }, { 1, -1 }).interceptX() << '\n';
}
```
Output:
```
3
```
