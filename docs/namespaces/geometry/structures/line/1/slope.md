# [xieite](../../../../../xieite.md)\:\:[geometry](../../../../../geometry.md)\:\:[Line](../../../line.md)\:\:slope
Defined in header [<xieite/geometry/line.hpp>](../../../../../../include/xieite/geometry/line.hpp)

&nbsp;

## Description
Computes the slope of this line.

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
#include <xieite/geometry/line.hpp>

int main() {
    std::cout << xieite::geometry::Line({ 0.0, 0.0 }, { 1.0, 1.0 }).slope() << '\n';
}
```
Output:
```
1
```
