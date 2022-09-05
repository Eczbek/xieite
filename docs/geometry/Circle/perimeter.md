# gcufl::geometry::Circle::perimeter
```cpp
double perimeter() const noexcept;
```
Calculates the perimeter of a circle.
## Example
```cpp
#include <gcufl/geometry.hpp>
#include <iostream>

int main() {
	std::cout << gcufl::geometry::Circle({ 0, 0 }, 1).perimeter() << '\n';
}
```
Output:
```
6.28318
```
