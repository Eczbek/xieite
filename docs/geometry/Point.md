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
constexpr Point(const double x = 0.0, const double y = 0.0) noexcept;
```

## Operators
```cpp
[[nodiscard]]
constexpr bool operator==(const xieite::geometry::Point other) const noexcept;
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
	const xieite::geometry::Point original(1.0, 0.0);
	const double angle = xieite::math::toRadians(90.0);
	const xieite::geometry::Point rotated = xieite::geometry::rotate(original, angle);
	std::cout << rotated.x << ' ' << rotated.y << '\n';
}
```
Output (rounded):
```
0 1
```
