# [xieite](../../../../../../xieite.md)\:\:[geometry](../../../../../../geometry.md)\:\:[Segment](../../../../segment.md)\:\:operator==
Defined in header [<xieite/geometry/segment.hpp>](../../../../../../../include/xieite/geometry/segment.hpp)

&nbsp;

## Description
Compares two segments.

&nbsp;

## Synopses
#### 1)
```cpp
[[nodiscard]] friend constexpr bool operator==(const xieite::geometry::Segment& segment1, const xieite::geometry::Segment& segment2) noexcept;
```

&nbsp;

## Example
```cpp
#include <iostream>
#include <xieite/geometry/ray.hpp>
#include <xieite/geometry/point.hpp>
#include <xieite/math/to_radians.hpp>

int main() {
    xieite::geometry::Segment segment1({ 0.0, 0.0 }, { 3.0, 4.0 });
    xieite::geometry::Segment segment2({ 3.0, 4.0 }, { 0.0, 0.0 });

    std::cout
        << std::boolalpha
        << (segment1 == segment2)
        << '\n';
}
```
Output:
```
true
```
