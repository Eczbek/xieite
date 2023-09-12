# [xieite](../../../xieite.md)\:\:[geometry](../../../geometry.md)\:\:[Line](../../Line.md)\:\:length
Defined in header [<xieite/geometry/Line.hpp>](../../../../include/xieite/geometry/Line.hpp)

&nbsp;

## Description
Always returns `std::numeric_limits<double>::infinity()`.

&nbsp;

## Synopses
#### 1)
```cpp
constexpr double length() const noexcept;
```

&nbsp;

## Example
```cpp
#include <iostream>
#include <xieite/geometry/Line.hpp>

int main() {
    std::cout << xieite::geometry::Line({ 0.0, 0.0 }, { 1.0, 1.0 }).length() << '\n';
}
```
Output:
```
inf
```
