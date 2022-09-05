# gcufl::geometry::Ellipse::contains
```cpp
bool contains(const gcufl::geometry::Point point) const noexcept;
```
Checks whether the ellipse contains a point
## Example
```cpp
#include <gcufl/geometry.hpp>
#include <iostream>

int main() {
	gcufl::geometry::Ellipse ellipse({ 0, 0 }, { 1, 2 });

	std::cout
		<< std::boolalpha
		<< ellipse.contains({ 0, 0 })
		<< '\n';
}
```
Output:
```
true
```
