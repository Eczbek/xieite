# [xieite](../xieite.md)\:\:[geometry](../geometry.md)\:\:getAngle
Defined in header [<xieite/geometry/getAngle.hpp>](../../include/xieite/geometry/getAngle.hpp)

&nbsp;

## Description
Calculates the angle of a line or between two points, in radians

&nbsp;

## Synopses

&nbsp;

```cpp
[[nodiscard]]
constexpr double getAngle(xieite::geometry::Point point1, xieite::geometry::Point point2) noexcept;
```
#### Function parameters
- `point1` - A `xieite::geometry::Point`
- `point2` - A `xieite::geometry::Point`
#### Return type
- `double` - The angle between two points

&nbsp;

```cpp
template<xieite::concepts::LinearShape LinearShape>
[[nodiscard]]
constexpr double getAngle(const LinearShape& linearShape) noexcept;
```
#### Template parameters
- `LinearShape` - A type satisfying `xieite::concepts::LinearShape`
#### Function parameters
- `linearShape` - A constant `LinearShape` reference
#### Return type
- `double` - The angle of the linear thing

&nbsp;

## Example
```cpp
#include <iostream>
#include <xieite/geometry/Line.hpp>
#include <xieite/geometry/Point.hpp>
#include <xieite/geometry/getAngle.hpp>

int main() {
    xieite::geometry::Point start(0.0, 0.0);
    xieite::geometry::Point end(1.0, 0.0);
    xieite::geometry::Line line(start, end);
    std::cout << xieite::geometry::getAngle(line) << '\n';
}
```
Output (rounded):
```
0
```
