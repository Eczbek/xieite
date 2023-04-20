# `xieite::geometry::getArea`
Defined in header [`<xieite/geometry/getArea.hpp>`](https://github.com/Eczbek/xieite/tree/main/include/xieite/geometry/getArea.hpp)

<br/>

Calculates the area of a shape.

<br/><br/>

## Synopses

<br/>

```cpp
[[nodiscard]]
constexpr double getArea(const xieite::geometry::Polygon& polygon) noexcept;
```
### Parameters
- `polygon` - A `xieite::geometry::Polygon` constant reference
### Return value
- `double` - Area of the shape

<br/>

```cpp
[[nodiscard]]
constexpr double getArea(const xieite::geometry::Ellipse& ellipse) noexcept;
```
### Parameters
- `ellipse` - A `xieite::geometry::Ellipse` constant reference
### Return value
- `double` - Area of the shape

<br/>

```cpp
[[nodiscard]]
constexpr double getArea(const xieite::geometry::Circle& circle) noexcept;
```
### Parameters
- `circle` - A `xieite::geometry::Circle` constant reference
### Return value
- `double` - Area of the shape

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

<br/><br/>

## See also
- [`xieite::geometry::Circle`](https://github.com/Eczbek/xieite/tree/main/docs/geometry/Circle.md)
- [`xieite::geometry::Ellipse`](https://github.com/Eczbek/xieite/tree/main/docs/geometry/Ellipse.md)
- [`xieite::geometry::Polygon`](https://github.com/Eczbek/xieite/tree/main/docs/geometry/Polygon.md)
