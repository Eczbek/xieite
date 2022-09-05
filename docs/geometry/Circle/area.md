# gcufl::geometry::Circle::area
```cpp
double area() const noexcept;
```
Calculates the area of a circle.
## Example
```cpp
#include <gcufl/geometry.hpp>
#include <iostream>

int main() {
	std::cout << gcufl::geometry::Circle({ 0, 0 }, 1).area() << '\n';
}
```
Output:
```
3.14159
```
