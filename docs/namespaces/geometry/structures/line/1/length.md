# [xieite](../../../../../xieite.md)\:\:[geometry](../../../../../geometry.md)\:\:[Line](../../../line.md)\:\:length
Defined in header [<xieite/geometry/line.hpp>](../../../../../../include/xieite/geometry/line.hpp)

&nbsp;

## Description
Always returns `std::numeric_limits<double>::infinity()`.

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
#include <xieite/geometry/line.hpp>

int main() {
    std::cout << xieite::geometry::Line({ 0.0, 0.0 }, { 1.0, 1.0 }).length() << '\n';
}
```
Output:
```
inf
```
