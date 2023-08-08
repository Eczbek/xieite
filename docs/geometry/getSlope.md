# [xieite](../xieite.md)\:\:[geometry](../geometry.md)\:\:getSlope
Defined in header [<xieite/geometry/getSlope.hpp>](../../include/xieite/geometry/getSlope.hpp)

&nbsp;

## Description
Calculates the slope of a line or between two points

&nbsp;

## Synopses

&nbsp;

```cpp
[[nodiscard]]
constexpr double getSlope(xieite::geometry::Point point1, xieite::geometry::Point point2) noexcept;
```
#### Function parameters
- `point1` - A `xieite::geometry::Point`
- `point2` - Also a `xieite::geometry::Point`
#### Return type
- `double`, the slope between the passed points, in radians

&nbsp;

```cpp
template<xieite::concepts::LinearShape LinearShape>
[[nodiscard]]
constexpr double getSlope(const LinearShape& linearShape) noexcept;
```
#### Template parameters
- `LinearShape` - A type satisfying `xieite::concepts::LinearShape`
#### Function parameters
- `linearShape` - A constant `LinearShape` reference
#### Return type
- `double`, the slope of the linear shape, in radians

&nbsp;

## Example
```cpp
#include <iostream>
#include <xieite/geometry/Line.hpp>
#include <xieite/geometry/getSlope.hpp>

int main() {
    std::cout << xieite::geometry::getSlope(xieite::geometry::Line({ 0.0, 0.0 }, { 2.0, 3.0 })) << '\n';
}
```
Output:
```
1.5
```
