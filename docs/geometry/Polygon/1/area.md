# [xieite](../../../xieite.md)\:\:[geometry](../../../geometry.md)\:\:[Polygon](../../Polygon.md)\:\:area
Defined in header [<xieite/geometry/Polygon.hpp>](../../../../include/xieite/geometry/Polygon.hpp)

&nbsp;

## Description
Computes the area of this polygon.

&nbsp;

## Synopses
#### 1)
```cpp
constexpr double area() const noexcept;
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
	}).area() << '\n';
}
```
Output:
```
4
```
