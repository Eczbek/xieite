# gcufl::geometry::Segment::length
```cpp
double length() const noexcept;
```
Calculates the length of the line segment.
## Example
```cpp
#include <iostream>
#include <gcufl/geometry.hpp>

int main() {
	std::cout << gcufl::geometry::Segment({ 3, 0 }, { 0, 4 }).length() << '\n';
}
```
Output:
```
5
```
