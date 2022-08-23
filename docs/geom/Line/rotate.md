# gcufl::geom::Line::rotate
```cpp
gcufl::geom::Line rotate(const double angle, const gcufl::geom::Point pivot = gcufl::geom::Point(0, 0));
```
Rotates a copy of the line about a pivot.
## Example
```cpp
#include <iostream>
#include <gcufl/geom>
#include <gcufl/math>

int main() {
	gcufl::geom::Line line1({ 0, 0 }, { 1, 1 });
	gcufl::geom::Line line2 = line1.rotate(gcufl::math::degToRad(90));

	std::cout << line1.slope() << '\n' << line2.slope() << '\n';
}
```
Output:
```
1
-1
```
