# [xieite](../../../xieite.md)\:\:[geometry](../../../geometry.md)\:\:[Polygon](../../Polygon.md)\:\:perimeter
Defined in header [<xieite/geometry/Polygon.hpp>](../../../../include/xieite/geometry/Polygon.hpp)

&nbsp;

## Description
Computes the perimeter of this polygon.

&nbsp;

## Synopses
#### 1)
```cpp
constexpr double perimeter() const noexcept;
```

&nbsp;

## Example
```cpp
#include <iostream>
#include <xieite/geometry/Point.hpp>
#include <xieite/geometry/Polygon.hpp>

int main() {
    std::cout << xieite::geometry::Polygon({
		xieite::geometry::Point(0, 0),
		xieite::geometry::Point(2, 0),
		xieite::geometry::Point(2, 2),
		xieite::geometry::Point(0, 2)
	}).perimeter() << '\n';
}
```
Output:
```
8
```
