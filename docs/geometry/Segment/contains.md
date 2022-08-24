# gcufl::geometry::Segment::contains
```cpp
bool contains(const gcufl::geometry::Point point) const noexcept;
```
Checks whether the segment intersects a point.
## Example
```cpp
#include <iostream>
#include <gcufl/geometry.hpp>

int main() {
	std::cout
		<< std::boolalpha
		<< gcufl::geometry::Segment({ 0, 0 }, { 2, 2 }).contains({ 1, 1 })
		<< '\n';
}
```
Output:
```
true
```
