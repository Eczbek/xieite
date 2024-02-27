# [xieite](../../../../../xieite.md)\:\:[geometry](../../../../../geometry.md)\:\:[Ray](../../../ray.md)\:\:length
Defined in header [<xieite/geometry/ray.hpp>](../../../../../../include/xieite/geometry/ray.hpp)

&nbsp;

## Description
Always returns `std::numeric_limits<double>::infinity()`.

&nbsp;

## Synopsis
#### 1)
```cpp
[[nodiscard]] constexpr double length() const noexcept;
```

&nbsp;

## Example
```cpp
#include <iostream>
#include "xieite/geometry/ray.hpp"

int main() {
    std::cout << xieite::geometry::Ray({ 0.0, 0.0 }, { 1.0, 1.0 }).length() << '\n';
}
```
Output:
```
inf
```
