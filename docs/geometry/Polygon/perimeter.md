# gcufl::geometry::Polygon::perimeter
```cpp
double perimeter() const noexcept;
```
Calculates the perimeter of a polygon.
## Example
```cpp
#include <gcufl/geometry.hpp>
#include <iostream>

int main() {
	std::cout << gcufl::geometry::Polygon({
		{ 0, 0 },
		{ 2, 0 },
		{ 2, 2 },
		{ 0, 2 }
	}).perimeter() << '\n';
}
```
Output:
```
8
```
