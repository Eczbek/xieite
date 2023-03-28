# xieite::geometry::getDistance
Defined in header `<xieite/geometry/getDistance.hpp>`

<br/>

Calculates the distance between two points.

<br/><br/>

## Declarations
```cpp
[[nodiscard]]
constexpr double getDistance(xieite::geometry::Point point1, xieite::geometry::Point point2) noexcept;
```

<br/><br/>

## Example
```cpp
#include <iostream>
#include <xieite/geometry/getDistance.hpp>

int main() {
	std::cout << xieite::geometry::getDistance({ 0.0, 0.0 }, { 3.0, 4.0 }) << '\n';
}
```
Output:
```
5
```
