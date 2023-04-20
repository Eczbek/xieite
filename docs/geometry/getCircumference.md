# `xieite::geometry::getCircumference`
Defined in header [`<xieite/geometry/getCircumference.hpp>`](https://github.com/Eczbek/xieite/tree/main/include/xieite/geometry/getCircumference.hpp)

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
#include <xieite/geometry/getCircumference.hpp>

int main() {
	std::cout << xieite::geometry::getCircumference(xieite::geometry::Circle({ 0.0, 0.0 }, 1.0)) << '\n';
}
```
Output:
```
6.28319
```

<br/><br/>

## See also
- [`xieite::geometry::Circle`](https://github.com/Eczbek/xieite/tree/main/docs/geometry/Circle.md)
- [`xieite::geometry::Ellipse`](https://github.com/Eczbek/xieite/tree/main/docs/geometry/Ellipse.md)
