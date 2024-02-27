# [xieite](../../../../../xieite.md)\:\:[geometry](../../../../../geometry.md)\:\:[Ray](../../../ray.md)\:\:slope
Defined in header [<xieite/geometry/ray.hpp>](../../../../../../include/xieite/geometry/ray.hpp)

&nbsp;

## Description
Computes the slope of this ray.

&nbsp;

## Synopsis
#### 1)
```cpp
[[nodiscard]] constexpr double slope() const noexcept;
```

&nbsp;

## Example
```cpp
#include <iostream>
#include "xieite/geometry/ray.hpp"

int main() {
    std::cout << xieite::geometry::Ray({ 0.0, 0.0 }, { 1.0, 1.0 }).slope() << '\n';
}
```
Output:
```
1
```
