# [`xieite`](../../README.md)`::`[`geometry`](../../docs/geometry.md)`::getCircumference`
Defined in header [`<xieite/geometry/getCircumference.hpp>`](../../include/xieite/geometry/getCircumference.hpp)

<br/>

Calculates the circumference of a circle, estimates the circumference of an ellipse.

<br/><br/>

## Synopsis

<br/>

```cpp
[[nodiscard]]
constexpr double getCircumference(const xieite::geometry::Ellipse& ellipse) noexcept;
```
### Parameters
- `ellipse` - A `xieite::geometry::Ellipse` constant reference to estimate the circumference of
### Return value
- `double` - The approximate circumference

<br/>

```cpp
[[nodiscard]]
constexpr double getCircumference(const xieite::geometry::Circle& circle) noexcept;
```
### Parameters
- `circle` - A `xieite::geometry::Circle` constant reference to calculate the circumference of
### Return value
- `double` - The circumference

<br/><br/>

## Example
```cpp
#include <iostream>
#include <xieite/geometry/Circle.hpp>
#include <xieite/geometry/Point.hpp>
#include <xieite/geometry/getCircumference.hpp>

int main() {
	xieite::geometry::Point center(0.0, 0.0);

	xieite::geometry::Circle circle(center, 1.0);

	std::cout << xieite::geometry::getCircumference(circle) << '\n';
}
```
Output:
```
6.28319
```

<br/><br/>

## See also
- [`xieite::geometry::Circle`](../../docs/geometry/Circle.md)
- [`xieite::geometry::Ellipse`](../../docs/geometry/Ellipse.md)
