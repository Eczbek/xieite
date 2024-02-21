# [xieite](../../../../../xieite.md)\:\:[geometry](../../../../../geometry.md)\:\:[Segment](../../../segment.md)\:\:angle
Defined in header [<xieite/geometry/segment.hpp"](../../../../../../include/xieite/geometry/segment.hpp)

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
#include "xieite/geometry/segment.hpp"

int main() {
    std::cout << xieite::geometry::Segment({ 0.0, 0.0 }, { 1.0, 1.0 }).angle() << '\n';
}
```
Output:
```
0.785398
```
