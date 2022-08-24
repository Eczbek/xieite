# gcufl::geometry::Circle::area
```cpp
double area() const noexcept;
```
Calculates the area of the circle.
## Example
```cpp
#include <iostream>
#include <gcufl/geometry.hpp>

int main() {
	gcufl::geometry::Circle circle({ 0, 0 }, 1);

	std::cout << circle.area() << '\n';
}
```
Output:
```
3.14159
```
