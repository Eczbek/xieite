# gcufl::geometry::Line::contains
```cpp
virtual bool contains(const gcufl::geometry::Point point) const noexcept;
```
Checks whether the line intersects a point.
## Example
```cpp
#include <iostream>
#include <gcufl/geometry.hpp>

int main() {
	std::cout
		<< std::boolalpha
		<< gcufl::geometry::Line({ 0, 0 }, { 1, 1 }).contains({ 5, 5 })
		<< '\n';
}
```
Output:
```
true
```
