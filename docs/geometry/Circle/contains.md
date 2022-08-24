# gcufl::geometry::Circle::contains
```cpp
bool contains(const gcufl::geometry::Point point) const noexcept;
```
Checks whether the circle contains a point
## Example
```cpp
#include <iostream>
#include <gcufl/geometry.hpp>

int main() {
	gcufl::geometry::Circle circle({ 0, 0 }, 1);

	std::cout
		<< std::boolalpha
		<< circle.contains({ 0, 0 })
		<< '\n';
}
```
Output:
```
true
```
