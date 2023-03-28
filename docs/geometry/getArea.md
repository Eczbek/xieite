# xieite::geometry::getArea
Defined in header `<xieite/geometry/getArea.hpp>`

<br/>

Calculates the area of a shape.

<br/><br/>

## Declarations
```cpp
[[nodiscard]]
constexpr double getArea(const xieite::geometry::Polygon& polygon) noexcept;
```
```cpp
[[nodiscard]]
constexpr double getArea(const xieite::geometry::Ellipse& ellipse) noexcept;
```
```cpp
[[nodiscard]]
constexpr double getArea(const xieite::geometry::Circle& circle) noexcept;
```

<br/><br/>

## Example
```cpp
#include <iostream>
#include <xieite/geometry/Circle.hpp>
#include <xieite/geometry/getArea.hpp>

int main() {
	std::cout << xieite::geometry::getArea(xieite::geometry::Circle({ 0.0, 0.0 }, 1.0)) << '\n';
}
```
