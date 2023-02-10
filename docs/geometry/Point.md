# xieite::geometry::Point
Declared in `<xieite/geometry/Point.hpp>`

<br/>

A 2D point.

<br/><br/>

## Member objects
```cpp
long double x;
```
```cpp
long double y;
```

## Constructor
```cpp
constexpr Point(const long double x = 0, const long double y = 0) noexcept;
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
#include <iostream> // std::cout
#include <xieite/geometry/Point.hpp>
#include <xieite/geometry/rotate.hpp>
#include <xieite/math/toRadians.hpp>

int main() {
	const xieite::geometry::Point original(1, 0);
	const long double angle = xieite::math::toRadians<long double>(90);
	const xieite::geometry::Point rotated = xieite::geometry::rotate(original, angle);
	std::cout << rotated.x << ' ' << rotated.y << '\n';
}
```
Output (rounded):
```
0 1
```
