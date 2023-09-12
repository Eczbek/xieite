# [xieite](../../../xieite.md)\:\:[geometry](../../../geometry.md)\:\:[Ray](../../Ray.md)\:\:slope
Defined in header [<xieite/geometry/Ray.hpp>](../../../../include/xieite/geometry/Ray.hpp)

&nbsp;

## Description
Computes the slope of this ray.

&nbsp;

## Synopses
#### 1)
```cpp
constexpr double slope() const noexcept;
```

&nbsp;

## Example
```cpp
#include <iostream>
#include <xieite/geometry/Ray.hpp>

int main() {
    std::cout << xieite::geometry::Ray({ 0.0, 0.0 }, { 1.0, 1.0 }).slope() << '\n';
}
```
Output:
```
1
```
