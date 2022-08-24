# gcufl::geometry::Ellipse::operator==
```cpp
bool operator==(const gcufl::geometry::Ellipse& other) const noexcept;
```
Compares two ellipses for equality.
## Example
```cpp
#include <iostream>
#include <gcufl/geometry.hpp>

int main() {
	gcufl::geometry::Ellipse ellipse1({ 0, 0 }, { 1, 2 });
	gcufl::geometry::Ellipse ellipse2({ 0, 0 }, { 1, 2 });

	std::cout
		<< std::boolalpha
		<< (ellipse1 == ellipse2)
		<< '\n';
}
```
Output:
```
true
```
