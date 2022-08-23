# gcufl::geom::Line::contains
```cpp
virtual bool contains(const gcufl::geom::Point point) const noexcept;
```
Checks whether the line intersects a point.
## Example
```cpp
#include <iostream>
#include <gcufl/geom>

int main() {
	std::cout << gcufl::geom::Line({ 0, 0 }, { 1, 1 }).contains({ 5, 5 }) << '\n';
}
```
Output:
```
true
```
