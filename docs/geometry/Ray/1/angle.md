# [xieite](../../../xieite.md)\:\:[geometry](../../../geometry.md)\:\:[Ray](../../Ray.md)\:\:angle
Defined in header [<xieite/geometry/Ray.hpp>](../../../../include/xieite/geometry/Ray.hpp)

&nbsp;

## Description
Computes the angle of this ray, in radians.

&nbsp;

## Synopses
#### 1)
```cpp
constexpr double angle() const noexcept;
```

&nbsp;

## Example
```cpp
#include <iostream>
#include <xieite/geometry/Ray.hpp>

int main() {
    std::cout << xieite::geometry::Ray({ 0.0, 0.0 }, { 1.0, 1.0 }).angle() << '\n';
}
```
Output:
```
0.785398
```
