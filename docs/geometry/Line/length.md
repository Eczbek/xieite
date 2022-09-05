# gcufl::geometry::Line::length
```cpp
double length() const noexcept;
```
Returns `std::numeric_limits<double>::infinity()`, as all lines are infinite.
## Example
```cpp
#include <gcufl/geometry.hpp>
#include <iostream>

int main() {
	std::cout << gcufl::geometry::Line({ 0, 0 }, { 1, 1 }).length() << '\n';
}
```
Output:
```
inf
```
