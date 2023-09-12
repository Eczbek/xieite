# [xieite](../../../../xieite.md)\:\:[geometry](../../../../geometry.md)\:\:[Line](../../../Line.md)\:\:operator==
Defined in header [<xieite/geometry/Line.hpp>](../../../../../include/xieite/geometry/Line.hpp)

&nbsp;

## Description
Compares two lines.

&nbsp;

## Synopses
#### 1)
```cpp
friend constexpr bool operator==(const xieite::geometry::Line& line1, const xieite::geometry::Line& line2) noexcept;
```

&nbsp;

## Example
```cpp
#include <iostream>
#include <xieite/geometry/Line.hpp>
#include <xieite/geometry/Point.hpp>
#include <xieite/math/toRadians.hpp>

int main() {
    xieite::geometry::Line line1({ 0.0, 0.0 }, { 1.0, 1.0 });
    xieite::geometry::Line line2({ 0.0, 0.0 }, xieite::math::toRadians(45.0));

    std::cout
        << std::boolalpha
        << (line1 == line2)
        << '\n';
}
```
Output:
```
true
```
