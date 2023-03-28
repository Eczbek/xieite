# xieite::geometry::Point
Defined in header `<xieite/geometry/Point.hpp>`

<br/>

A struct representing a point.

<br/><br/>

## Member objects
```cpp
double x;
```
```cpp
double y;
```

## Constructors
```cpp
constexpr Point(double x = 0.0, double y = 0.0) noexcept;
```

## Operators
```cpp
[[nodiscard]]
constexpr bool operator==(xieite::geometry::Point other) const noexcept;
```
(`operator!=` is defined implicitly)

<br/><br/>

## Example
```cpp
#include <iostream>
#include <xieite/geometry/Point.hpp>
#include <xieite/geometry/rotate.hpp>
#include <xieite/math/toRadians.hpp>

int main() {
	xieite::geometry::Point point = xieite::geometry::rotate({ 1.0, 0.0 }, xieite::math::toRadians(90.0));
	
	std::cout << point.x << ' ' << point.y << '\n';
}
```
Output (rounded):
```
0 1
```
