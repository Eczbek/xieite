# `xieite::geometry::Line::Line`
Defined in header [`<xieite/geometry/Line.hpp>`](https://github.com/Eczbek/xieite/tree/main/include/xieite/geometry/Line.hpp)

<br/>

Constructs a `xieite::geometry::Line`.

<br/><br/>

## Synopsis

<br/>

```cpp
constexpr Line(xieite::geometry::Point start, xieite::geometry::Point end) noexcept;
```
### Parameters
- `start` - A `xieite::geometry::Point` copy, one intersection through which the infinite line passes
- `end` - A `xieite::geometry::Point` copy, another intersection through which the infinite line passes

<br/>

```cpp
constexpr Line(xieite::geometry::Point start, double angle) noexcept;
```
### Parameters
- `start` - A `xieite::geometry::Point` copy, an intersection through which the infinite line passes
- `angle` - A `double` copy, the line's angle

<br/><br/>

## Example
```cpp
#include <iostream>
#include <xieite/geometry/Line.hpp>
#include <xieite/geometry/getAngle.hpp>

int main() {
	std::cout << xieite::geometry::getAngle(xieite::geometry::Line({ 0.0, 0.0 }, { 1.0, 1.0 })) << '\n';
}
```
Output:
```
0.785398
```

<br/><br/>

## See also
- [`xieite::geometry::Line`](https://github.com/Eczbek/xieite/tree/main/docs/geometry/Line.md)
- [`xieite::geometry::Point`](https://github.com/Eczbek/xieite/tree/main/docs/geometry/Point.md)
