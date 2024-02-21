# [xieite](../../../../../xieite.md)\:\:[geometry](../../../../../geometry.md)\:\:[Line](../../../line.md)\:\:angle
Defined in header [<xieite/geometry/line.hpp"](../../../../../../include/xieite/geometry/line.hpp)

&nbsp;

## Description
Computes the angle of this line, in radians.

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
#include "xieite/geometry/line.hpp"

int main() {
    std::cout << xieite::geometry::Line({ 0.0, 0.0 }, { 1.0, 1.0 }).angle() << '\n';
}
```
Output:
```
0.785398
```
