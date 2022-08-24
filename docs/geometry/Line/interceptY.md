# gcufl::geometry::Line::interceptY
```cpp
double interceptY() const noexcept;
```
Calculates the y-intercept of the line.
## Example
```cpp
#include <iostream>
#include <gcufl/geometry.hpp>

int main() {
	std::cout << gcufl::geometry::Line({ 1, 2 }, { 1, -1 }).interceptY() << '\n';
}
```
Output:
```
3
```
