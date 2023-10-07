# [xieite](../../../../../xieite.md)\:\:[geometry](../../../../../geometry.md)\:\:[Segment](../../../Segment.md)\:\:angle
Defined in header [<xieite/geometry/Segment.hpp>](../../../../../../include/xieite/geometry/Segment.hpp)

&nbsp;

## Description
Computes the angle of this segment, in radians.

&nbsp;

## Synopses
#### 1)
```cpp
[[nodiscard]] constexpr double angle() const noexcept;
```

&nbsp;

## Example
```cpp
#include <iostream>
#include <xieite/geometry/Segment.hpp>

int main() {
    std::cout << xieite::geometry::Segment({ 0.0, 0.0 }, { 1.0, 1.0 }).angle() << '\n';
}
```
Output:
```
0.785398
```
