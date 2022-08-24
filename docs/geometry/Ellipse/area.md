# gcufl::geometry::Ellipse::area
```cpp
double area() const noexcept;
```
Calculates the area of the ellipse.
## Example
```cpp
#include <iostream>
#include <gcufl/geometry.hpp>

int main() {
	gcufl::geometry::Ellipse ellipse({ 0, 0 }, { 1, 2 });

	std::cout << ellipse.area() << '\n';
}
```
Output:
```
6.28319
```
