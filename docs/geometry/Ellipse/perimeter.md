# gcufl::geometry::Ellipse::perimeter
```cpp
double perimiter() const noexcept;
```
Calculates the perimeter of the ellipse.
## Example
```cpp
#include <iostream>
#include <gcufl/geometry.hpp>

int main() {
	gcufl::geometry::Ellipse ellipse({ 0, 0 }, { 1, 2 });

	std::cout << ellipse.perimeter() << '\n';
}
```
Output:
```
9.93459
```
