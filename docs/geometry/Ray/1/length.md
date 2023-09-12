# [xieite](../../../xieite.md)\:\:[geometry](../../../geometry.md)\:\:[Ray](../../Ray.md)\:\:length
Defined in header [<xieite/geometry/Ray.hpp>](../../../../include/xieite/geometry/Ray.hpp)

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
#include <xieite/geometry/Ray.hpp>

int main() {
    std::cout << xieite::geometry::Ray({ 0.0, 0.0 }, { 1.0, 1.0 }).length() << '\n';
}
```
Output:
```
inf
```
