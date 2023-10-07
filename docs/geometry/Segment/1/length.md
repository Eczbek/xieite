# [xieite](../../../xieite.md)\:\:[geometry](../../../geometry.md)\:\:[Segment](../../Segment.md)\:\:length
Defined in header [<xieite/geometry/Segment.hpp>](../../../../include/xieite/geometry/Segment.hpp)

&nbsp;

## Description
Computes the distance between the start and end of this segment.

&nbsp;

## Synopses
#### 1)
```cpp
[[nodiscard]] constexpr double length() const noexcept;
```

&nbsp;

## Example
```cpp
#include <iostream>
#include <xieite/geometry/Segment.hpp>

int main() {
    std::cout << xieite::geometry::Segment({ 0.0, 0.0 }, { 1.0, 1.0 }).length() << '\n';
}
```
Output:
```
1.41421
```
