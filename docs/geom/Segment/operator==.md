# gcufl::geom::Segment::operator==
```cpp
bool operator==(const gcufl::geom::Segment& other) const noexcept;
```
Compares two line segments for equality.
## Example
```cpp
#include <iostream>
#include <gcufl/geom>

int main() {
	gcufl::geom::Segment segment1({ 0, 0 }, { 2, 2 });
	gcufl::geom::Segment segment2({ 0, 0 }, { 2, 2 });

	std::cout
		<< std::boolalpha
		<< (segment1 == segment2)
		<< '\n';
}
```
Output:
```
true
```
