# gcufl::geometry::Line::interceptY
```cpp
double interceptY() const noexcept;
```
Calculates the y-intercept of a line.
## Example
```cpp
#include <gcufl/geometry.hpp>
#include <iostream>

int main() {
	std::cout << gcufl::geometry::Line({ 1, 2 }, { 1, -1 }).interceptY() << '\n';
}
```
Output:
```
3
```
