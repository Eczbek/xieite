# `xieite::geometry::Circle::Circle`
Defined in header [`<xieite/geometry/Circle.hpp>`](https://github.com/Eczbek/xieite/tree/main/include/xieite/geometry/Circle.hpp)

<br/>

Constructs a `xieite::geometry::Circle`.

<br/><br/>

## Synopsis

<br/>

```cpp
constexpr Circle(xieite::geometry::Point center, double radius) noexcept;
```
### Parameters
- `center` - A `xieite::geometry::Point` copy, determining the center of the constructed circle
- `radius` - A `double` copy for the circle's radius

<br/><br/>

## Example
```cpp
#include <iostream>
#include <xieite/geometry/Circle.hpp>
#include <xieite/geometry/getArea.hpp>

int main() {
	std::cout << xieite::geometry::getArea(xieite::geometry::Circle({ 0.0, 0.0 }, 3.0)) << '\n';
}
```
Output:
```
28.2743
```

<br/><br/>

## See also
- [`xieite::geometry::Circle`](https://github.com/Eczbek/xieite/tree/main/docs/geometry/Circle.md)
- [`xieite::geometry::Point`](https://github.com/Eczbek/xieite/tree/main/docs/geometry/Point.md)
