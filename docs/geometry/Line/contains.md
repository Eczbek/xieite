# gcufl::geometry::Line::contains
```cpp
virtual bool contains(const gcufl::geometry::Point point) const noexcept;
```
Checks whether the line intersects a point.
## Example
```cpp
#include <gcufl/geometry.hpp>
#include <iostream>

int main() {
	gcufl::geometry::Line line({ 0, 0 }, { 1, 1 })

	std::cout << std::boolalpha << line.contains({ 5, 5 }) << '\n';
}
```
Output:
```
true
```
