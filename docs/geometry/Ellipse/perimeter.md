# gcufl::geometry::Ellipse::perimeter
```cpp
double perimiter() const noexcept;
```
Calculates the perimeter of an ellipse.
## Example
```cpp
#include <gcufl/geometry.hpp>
#include <iostream>

int main() {
	std::cout << gcufl::geometry::Ellipse({ 0, 0 }, { 1, 2 }).perimeter() << '\n';
}
```
Output:
```
9.93459
```
