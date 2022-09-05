# gcufl::geometry::Segment::length
```cpp
double length() const noexcept;
```
Calculates the length of the line segment.
## Example
```cpp
#include <gcufl/geometry.hpp>
#include <iostream>

int main() {
	gcufl::geometry::Segment segment({ 3, 0 }, { 0, 4 });

	std::cout << segment.length() << '\n';
}
```
Output:
```
5
```
