# gcufl::geom::Segment::contains
```cpp
bool contains(const gcufl::geom::Point point) const noexcept;
```
Checks whether the segment intersects a point.
## Example
```cpp
#include <iostream>
#include <gcufl/geom>

int main() {
	std::cout
		<< std::boolalpha
		<< gcufl::geom::Segment({ 0, 0 }, { 2, 2 }).contains({ 1, 1 })
		<< '\n';
}
```
Output:
```
true
```
