# gcufl::geometry::Segment::length
```cpp
double length() const noexcept;
```
Calculates the length of a line segment.
## Example
```cpp
#include <gcufl/geometry.hpp>
#include <iostream>

int main() {
	std::cout << gcufl::geometry::Segment({ 3, 0 }, { 0, 4 }).length() << '\n';
}
```
Output:
```
5
```
