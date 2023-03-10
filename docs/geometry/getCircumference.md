# xieite::geometry::getCircumference
Defined in header `<xieite/geometry/getCircumference.hpp>`

<br/>

Calculates the circumference of a circle, estimates the circumference of an ellipse.

<br/><br/>

## Declarations
```cpp
[[nodiscard]]
constexpr double getCircumference(const xieite::geometry::Ellipse& ellipse) noexcept;
```
```cpp
[[nodiscard]]
constexpr double getCircumference(const xieite::geometry::Circle& circle) noexcept;
```

<br/><br/>

## Example
```cpp
#include <iostream> // std::cout
#include <xieite/geometry/Circle.hpp>
#include <xieite/geometry/getCircumference.hpp>

int main() {
	const xieite::geometry::Circle circle({ 0, 0 }, 1);
	std::cout << xieite::geometry::getCircumference(circle) << '\n';
}
```
Output:
```
6.28319
```
