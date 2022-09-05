# gcufl::geometry::Line::length
```cpp
double length() const noexcept;
```
Returns `std::numeric_limits<double>::infinity()`, as the line is infinite.
## Example
```cpp
#include <gcufl/geometry.hpp>
#include <iostream>

int main() {
	gcufl::geometry::Line line({ 0, 0 }, { 1, 1 })

	std::cout << line.length() << '\n';
}
```
Output:
```
inf
```
