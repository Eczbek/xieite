# xieite::geometry::Ellipse
Declared in `<xieite/geometry/Ellipse.hpp>`

<br/>

A 2D ellipse.

<br/><br/>

## Member objects
```cpp
xieite::geometry::Point center;
```
```cpp
xieite::geometry::Point radius;
```
```cpp
double rotation;
```

## Constructor
```cpp
constexpr Ellipse(const xieite::geometry::Point center, const xieite::geometry::Point radius, const double rotation = 0) noexcept;
```

## Operators
```cpp
[[nodiscard]]
constexpr bool operator==(const xieite::geometry::Ellipse& other) const noexcept;
```
(`operator!=` is defined implicitly)

## Other methods
```cpp
[[nodiscard]]
virtual constexpr double area() const noexcept;
```
```cpp
[[nodiscard]]
virtual constexpr xieite::geometry::Polygon boundingBox() const noexcept;
```
```cpp
[[nodiscard]]
virtual constexpr bool contains(const xieite::geometry::Point point) const noexcept;
```
```cpp
[[nodiscard]]
constexpr std::vector<xieite::geometry::Point> intersections(const xieite::geometry::Line& line) const noexcept;
```
```cpp
[[nodiscard]]
virtual constexpr double perimeter() const noexcept;
```
```cpp
[[nodiscard]]
constexpr xieite::geometry::Ellipse rotate(const double angle, const xieite::geometry::Point pivot = xieite::geometry::Point(0, 0)) const noexcept;
```

<br/><br/>

## Example
```cpp
#include <iostream>
#include <xieite/geometry/Ellipse.hpp>

int main() {
	std::cout << xieite::geometry::Ellipse({ 0, 0 }, { 1, 2 }).area() << '\n';
}
```
Output:
```
6.28319
```
