# gcufl::geometry::Line::length
```cpp
double length() const noexcept;
```
Returns `std::numeric_limits<double>::infinity()`, as the line is infinite.
## Example
```cpp
#include <iostream>
#include <gcufl/geometry.hpp>

int main() {
	std::cout << gcufl::geometry::Line({ 0, 0 }, { 1, 1 }).length() << '\n';
}
```
Output:
```
inf
```
