# [xieite](../xieite.md)\:\:[geometry](../geometry.md)\:\:getSides
Defined in header p<xieite/geometry/getSides.hpp>](../../include/xieite/geometry/getSides.hpp)

&nbsp;

## Description
Creates line segments between the points of a polygon

&nbsp;

## Synopsis
```cpp
[[nodiscard]]
constexpr std::vector<xieite::geometry::Segment> getSides(const xieite::geometry::Polygon& polygon) noexcept;
```
#### Function parameters
- `polygon` - A `xieite::geometry::Polygon` constant reference
#### Return type

&nbsp;

## Example
```cpp
#include <iostream>
#include <xieite/geometry/Polygon.hpp>
#include <xieite/geometry/Segment.hpp>
#include <xieite/geometry/getLength.hpp>
#include <xieite/geometry/getSides.hpp>

int main() {
    xieite::geometry::Polygon rectangle {
        { 0.0, 0.0 },
        { 3.0, 0.0 },
        { 3.0, 2.0 },
        { 0.0, 2.0 }
    };

    for (xieite::geometry::Segment& side : xieite::geometry::getSides(rectangle)) {
        std::cout << xieite::geometry::getLength(side) << '\n';
    }
}
```
Output:
```
3
2
3
2
```
