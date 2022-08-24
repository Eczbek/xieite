# gcufl::geometry::Circle::perimeter
```cpp
double perimeter() const noexcept;
```
Calculates the perimeter of the circle.
## Example
```cpp
#include <iostream>
#include <gcufl/geometry.hpp>

int main() {
	gcufl::geometry::Circle circle({ 0, 0 }, 1);

	std::cout << circle.perimeter() << '\n';
}
```
Output:
```
6.28318
```
