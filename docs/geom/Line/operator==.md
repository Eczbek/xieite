# gcufl::geom::Line::operator==
```cpp
bool operator==(const gcufl::geom::Line& other) const noexcept;
```
Compares two lines for equality.
## Example
```cpp
#include <iostream>
#include <gcufl/geom>
#include <gcufl/math>

int main() {
	gcufl::geom::Line line1({ 0, 0 }, { 1, 1 });
	gcufl::geom::Line line2({ 3, 3 }, gcufl::math::degToRad(45));

	std::cout << (line1 == line2) << '\n';
}
```
Output:
```
true
```
