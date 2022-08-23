# gcufl::geom::Line::interceptY
```cpp
double interceptY() const noexcept;
```
Calculates the y-intercept of the line.
## Example
```cpp
#include <iostream>
#include <gcufl/geom>

int main() {
	std::cout << gcufl::geom::Line({ 1, 2 }, { 1, -1 }).interceptY() << '\n';
}
```
Output:
```
3
```
