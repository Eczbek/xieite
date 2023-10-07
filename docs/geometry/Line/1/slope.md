# [xieite](../../../xieite.md)\:\:[geometry](../../../geometry.md)\:\:[Line](../../Line.md)\:\:slope
Defined in header [<xieite/geometry/Line.hpp>](../../../../include/xieite/geometry/Line.hpp)

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
#include <xieite/geometry/Line.hpp>

int main() {
    std::cout << xieite::geometry::Line({ 0.0, 0.0 }, { 1.0, 1.0 }).slope() << '\n';
}
```
Output:
```
1
```
