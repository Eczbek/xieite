# gcufl::geom::Line::interceptX
```cpp
double interceptX() const noexcept;
```
Calculates the x-intercept of the line.
## Example
```cpp
#include <iostream>
#include <gcufl/geom>

int main() {
	std::cout << gcufl::geom::Line({ 1, 2 }, { 1, -1 }).interceptX() << '\n';
}
```
Output:
```
3
```
