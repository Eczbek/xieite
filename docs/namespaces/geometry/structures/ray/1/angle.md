# [xieite](../../../../../xieite.md)\:\:[geometry](../../../../../geometry.md)\:\:[Ray](../../../ray.md)\:\:angle
Defined in header [<xieite/geometry/ray.hpp>](../../../../../../include/xieite/geometry/ray.hpp)

&nbsp;

## Description
Computes the angle of this ray, in radians.

&nbsp;

## Synopsis
#### 1)
```cpp
[[nodiscard]] constexpr double angle() const noexcept;
```

&nbsp;

## Example
```cpp
#include <iostream>
#include "xieite/geometry/ray.hpp"

int main() {
    std::cout << xieite::geometry::Ray({ 0.0, 0.0 }, { 1.0, 1.0 }).angle() << '\n';
}
```
Output:
```
0.785398
```
