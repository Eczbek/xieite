# xieite::geometry::Polygon
Declared in `<xieite/geometry/Polygon.hpp>`

<br/>

A 2D polygon.

<br/><br/>

## Member objects
```cpp
std::vector<xieite::geometry::Point> points;
```

## Constructor
```cpp
constexpr Polygon(const std::vector<xieite::geometry::Point>& points) noexcept;
```

## Operators
```cpp
[[nodiscard]]
constexpr bool operator==(const xieite::geometry::Polygon& other) const noexcept;
```
(`operator!=` is defined implicitly)

## Other methods
```cpp
[[nodiscard]]
constexpr double area() const noexcept;
```
```cpp
[[nodiscard]]
constexpr bool contains(const xieite::geometry::Point point) const noexcept;
```
```cpp
[[nodiscard]]
constexpr double perimeter() const noexcept;
```
```cpp
[[nodiscard]]
constexpr xieite::geometry::Polygon rotate(const double angle, const xieite::geometry::Point pivot = xieite::geometry::Point(0, 0)) const noexcept;
```
```cpp
[[nodiscard]]
constexpr std::vector<xieite::geometry::Segment> sides() const noexcept;
```

<br/><br/>

## Example
```cpp
#include <iostream>
#include <xieite/geometry/Polygon.hpp>

int main() {
	std::cout << xieite::geometry::Polygon({
		{ 1, 0 }, // (Diamond shape)
		{ 2, 1 }, //    x
		{ 1, 2 }, //  x   x
		{ 0, 1 }  //    x
	}).area() << '\n';
}
```
Output:
```
1
```
