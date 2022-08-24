# gcufl::geometry::Line::interceptX
```cpp
double interceptX() const noexcept;
```
Calculates the x-intercept of the line.
## Example
```cpp
#include <iostream>
#include <gcufl/geometry.hpp>

int main() {
	std::cout << gcufl::geometry::Line({ 1, 2 }, { 1, -1 }).interceptX() << '\n';
}
```
Output:
```
3
```
