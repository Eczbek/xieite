# [xieite](../xieite.md)\:\:[geometry](../geometry.md)\:\:rotate
Defined in header [<xieite/geometry/rotate.hpp>](../../include/xieite/geometry/rotate.hpp)

&nbsp;

## Description
Rotates shapes a specific angle around any pivot, clockwise

&nbsp;

## Synopses

&nbsp;

```cpp
[[nodiscard]]
constexpr xieite::geometry::Point rotate(xieite::geometry::Point point, double angle, xieite::geometry::Point pivot = xieite::geometry::Point(0, 0)) noexcept;
```
#### Function parameters
- `point` - A `xieite::geometry::Point`
- `angle` - A `double`, clockwise rotation in radians
- `pivot` - A `xieite::geometry::Point`, is `{ 0, 0 }` by default
#### Return type
- new rotated `xieite::geometry::Point`

&nbsp;

```cpp
template<xieite::concepts::LinearShape LinearShape>
[[nodiscard]]
constexpr LinearShape rotate(const LinearShape& linearShape, double angle, xieite::geometry::Point pivot = xieite::geometry::Point(0, 0)) noexcept;
```
#### Template parameters
- `LinearShape` - The type of the passed linear shape satisfying `xieite::concepts::LinearShape`
#### Function parameters
- `linearShape` - A `LinearShape` constant reference
- `angle` - A `double`, clockwise rotation in radians
- `pivot` - A `xieite::geometry::Point`, is `{ 0, 0 }` by default
#### Return type
- new rotated `LinearShape`

&nbsp;

```cpp
[[nodiscard]]
constexpr xieite::geometry::Polygon rotate(xieite::geometry::Polygon polygon, double angle, xieite::geometry::Point pivot = xieite::geometry::Point(0, 0)) noexcept;
```
#### Function parameters
- `polygon` - A `xieite::geometry::Polygon` constant reference
- `angle` - A `double`, clockwise rotation in radians
- `pivot` - A `xieite::geometry::Point`, is `{ 0, 0 }` by default
#### Return type
- new rotated `xieite::geometry::Polygon`

&nbsp;

## Example
```cpp
#include <iostream>
#include <xieite/geometry/Line.hpp>
#include <xieite/geometry/getSlope.hpp>
#include <xieite/geometry/rotate.hpp>
#include <xieite/math/toRadians.hpp>

int main() {
    xieite::geometry::Line line1({ 0, 0 }, { 1, 1 });

    xieite::geometry::Line line2 = xieite::geometry::rotate(line1, xieite::math::toRadians(90.0));

    std::cout
        << xieite::geometry::getSlope(line1) << '\n'
        << xieite::geometry::getSlope(line2) << '\n';
}
```
Output:
```
1
-1
```
