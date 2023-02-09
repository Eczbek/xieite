# xieite::geometry::getDistance
Declared in `<xieite/geometry/getDistance.hpp>`

<br/>

Calculates the distance between two points.

<br/><br/>

## Declaration
```cpp
[[nodiscard]]
constexpr long double getDistance(const xieite::geometry::Point point1, const xieite::geometry::Point point2) noexcept;
```

<br/><br/>

## Example
```cpp
#include <iostream>
#include <xieite/geometry/getDistance.hpp>

int main() {
	std::cout << xieite::geometry::getDistance({ 0, 0 }, { 3, 4 }) << '\n';
}
```
Output:
```
5
```
