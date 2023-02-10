# xieite::geometry::getArea
Declared in `<xieite/geometry/getArea.hpp>`

<br/>

Calculates the area of a shape.

<br/><br/>

## Declarations
```cpp
[[nodiscard]]
constexpr long double getArea(const xieite::geometry::Polygon& polygon) noexcept;
```
```cpp
[[nodiscard]]
constexpr long double getArea(const xieite::geometry::Ellipse& ellipse) noexcept;
```
```cpp
[[nodiscard]]
constexpr long double getArea(const xieite::geometry::Circle& circle) noexcept;
```

<br/><br/>

## Example
```cpp
#include <iostream> // std::cout
#include <xieite/geometry/Circle.hpp>
#include <xieite/geometry/getArea.hpp>

int main() {
	xieite::geometry::Circle circle({ 0, 0 }, 1);
	std::cout << xieite::geometry::getArea(circle) << '\n';
}
```
