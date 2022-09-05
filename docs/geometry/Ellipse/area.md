# gcufl::geometry::Ellipse::area
```cpp
double area() const noexcept;
```
Calculates the area of an ellipse.
## Example
```cpp
#include <gcufl/geometry.hpp>
#include <iostream>

int main() {
	std::cout << gcufl::geometry::Ellipse({ 0, 0 }, { 1, 2 }).area() << '\n';
}
```
Output:
```
6.28319
```
