# [xieite](../../xieite.md)\:\:[geometry](../../geometry.md)\:\:[Line](../Line.md)\:\:operator==
Defined in header [<xieite/geometry/Line.hpp>](../../../include/xieite/geometry/Line.hpp)

&nbsp;

## Description
Compares two lines to each other

&nbsp;

## Synopsis
```cpp
[[nodiscard]]
constexpr bool operator==(const xieite::geometry::Line& line) const noexcept;
```
#### Function parameters
- `line` - A `xieite::geometry::Line` constant reference
#### Return type
- `bool` - Whether or not the compared shapes are equal

&nbsp;

## Example
```cpp
#include <iostream>
#include <xieite/geometry/Line.hpp>
#include <xieite/geometry/Point.hpp>
#include <xieite/math/toRadians.hpp>

int main() {
    xieite::geometry::Point start(0.0, 0.0);
    xieite::geometry::Point end(1.0, 1.0);

    xieite::geometry::Line line1(start, end);
    xieite::geometry::Line line2(start, xieite::math::toRadians(45.0));

    std::cout
        << std::boolalpha
        << (line1 == line2) << '\n';
}
```
Output:
```
true
```
