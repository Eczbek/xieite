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
	gcufl::geometry::Segment segment({ 0, 0 }, { 2, 2 });

	std::cout << std::boolalpha << segment.contains({ 1, 1 }) << '\n';
}
```
Output:
```
true
```
