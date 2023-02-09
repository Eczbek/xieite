# xieite::geometry::getCircumference
Declared in `<xieite/geometry/getCircumference.hpp>`

<br/>

Calculates the circumference of an ellipse or circle.

<br/><br/>

## Declarations
```cpp
[[nodiscard]]
constexpr long double getCircumference(const xieite::geometry::Ellipse& ellipse) noexcept;
```
```cpp
[[nodiscard]]
constexpr long double getCircumference(const xieite::geometry::Circle& circle) noexcept;
```

<br/><br/>

## Example
```cpp
#include <iostream>
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
