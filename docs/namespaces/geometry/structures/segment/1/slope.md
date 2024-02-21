# [xieite](../../../../../xieite.md)\:\:[geometry](../../../../../geometry.md)\:\:[Segment](../../../segment.md)\:\:slope
Defined in header [<xieite/geometry/segment.hpp"](../../../../../../include/xieite/geometry/segment.hpp)

&nbsp;

## Description
Computes the slope of this segment.

&nbsp;

## Synopses
#### 1)
```cpp
[[nodiscard]] constexpr double slope() const noexcept;
```

&nbsp;

## Example
```cpp
#include <iostream>
#include "xieite/geometry/segment.hpp"

int main() {
    std::cout << xieite::geometry::Segment({ 0.0, 0.0 }, { 1.0, 1.0 }).slope() << '\n';
}
```
Output:
```
1
```
