# [xieite](../../xieite.md)\:\:[geometry](../../geometry.md)\:\:[Line](../Line.md)\:\:Line
Defined in header [<xieite/geometry/Line.hpp>](../../../include/xieite/geometry/Line.hpp)

&nbsp;

## Description
Constructs a `xieite::geometry::Line`

&nbsp;

## Synopsis
```cpp
constexpr Line(xieite::geometry::Point start, xieite::geometry::Point end) noexcept;
```
#### Function parameters
- `start` - A `xieite::geometry::Point`, one intersection through which the infinite line passes
- `end` - A `xieite::geometry::Point`, another intersection through which the infinite line passes

&nbsp;

```cpp
constexpr Line(xieite::geometry::Point start, double angle) noexcept;
```
#### Function parameters
- `start` - A `xieite::geometry::Point`, an intersection through which the infinite line passes
- `angle` - A `double`, the line's angle

&nbsp;

## Example
```cpp
#include <iostream>
#include <xieite/geometry/Line.hpp>
#include <xieite/geometry/Point.hpp>
#include <xieite/geometry/getAngle.hpp>

int main() {
    xieite::geometry::Point start(0.0, 0.0);
    xieite::geometry::Point end(1.0, 1.0);

    xieite::geometry::Line line(start, end);

    std::cout << xieite::geometry::getAngle(line) << '\n';
}
```
Output:
```
0.785398
```
