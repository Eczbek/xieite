# [xieite](../../../../xieite.md)\:\:[geometry](../../../../geometry.md)\:\:[Segment](../../../Segment.md)\:\:operator==
Defined in header [<xieite/geometry/Segment.hpp>](../../../../../include/xieite/geometry/Segment.hpp)

&nbsp;

## Description
Compares two segments.

&nbsp;

## Synopses
#### 1)
```cpp
friend constexpr bool operator==(const xieite::geometry::Segment& segment1, const xieite::geometry::Segment& segment2) noexcept;
```

&nbsp;

## Example
```cpp
#include <iostream>
#include <xieite/geometry/Ray.hpp>
#include <xieite/geometry/Point.hpp>
#include <xieite/math/toRadians.hpp>

int main() {
    xieite::geometry::Point start(0.0, 0.0);
	xieite::geometry::Point end(3.0, 4.0);

    xieite::geometry::Segment segment1(start, end);
    xieite::geometry::Segment segment2(end, start);

    std::cout
        << std::boolalpha
        << (segment1 == segment2) << '\n';
}
```
Output:
```
true
```
