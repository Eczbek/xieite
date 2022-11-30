# xieite::geometry::Point
Declared in `<xieite/geometry/Point.hpp>`

<br/>

A 2D point.

<br/><br/>

## Member objects
```cpp
double x;
```
```cpp
double y;
```

## Constructor
```cpp
constexpr Point(const double x = 0, const double y = 0) noexcept;
```

## Operators
```cpp
[[nodiscard]]
constexpr bool operator==(const xieite::geometry::Point other) const noexcept;
```
(`operator!=` is defined implicitly)

## Other methods
```cpp
[[nodiscard]]
constexpr xieite::geometry::Point rotate(const double angle, const xieite::geometry::Point pivot = xieite::geometry::Point(0, 0)) const noexcept;
```

<br/><br/>

## Example
```cpp
#include <iostream>
#include <xieite/geometry/Point.hpp>
#include <xieite/math/toRadians.hpp>

int main() {
	xieite::geometry::Point original(0, 1);
	xieite::geometry::Point rotated = original.rotate(xieite::math::toRadians(90));
	std::cout << rotated.x << ' ' << rotated.y << '\n';
}
```
Output: (rounded slightly)
```
1 0
```
