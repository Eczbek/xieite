# [xieite](../../../../xieite.md)\:\:[geometry](../../../../geometry.md)\:\:[Line](../../../Line.md)\:\:Line
Defined in header [<xieite/geometry/Line.hpp>](../../../../../include/xieite/geometry/Line.hpp)

&nbsp;

## Description
Constructs a `xieite::geometry::Line`.

&nbsp;

## Synopses
#### 1)
```cpp
constexpr Line(xieite::geometry::Point start, xieite::geometry::Point end) noexcept;
```
#### 2)
```cpp
constexpr Line(xieite::geometry::Point start, double angle) noexcept;
```

&nbsp;

## Example
```cpp
#include <iostream>
#include <xieite/geometry/Line.hpp>
#include <xieite/geometry/Point.hpp>
#include <xieite/geometry/getAngle.hpp>

int main() {
    std::cout << xieite::geometry::Line({ 0.0, 0.0 }, { 1.0, 1.0 }).angle() << '\n';
}
```
Output:
```
0.785398
```
