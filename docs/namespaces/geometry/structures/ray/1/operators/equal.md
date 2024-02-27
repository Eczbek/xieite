# [xieite](../../../../../../xieite.md)\:\:[geometry](../../../../../../geometry.md)\:\:[Ray](../../../../ray.md)\:\:operator==
Defined in header [<xieite/geometry/ray.hpp>](../../../../../../../include/xieite/geometry/ray.hpp)

&nbsp;

## Description
Compares two rays.

&nbsp;

## Synopsis
#### 1)
```cpp
[[nodiscard]] friend constexpr bool operator==(const xieite::geometry::Ray& ray1, const xieite::geometry::Ray& ray2) noexcept;
```

&nbsp;

## Example
```cpp
#include <iostream>
#include "xieite/geometry/ray.hpp"
#include "xieite/geometry/point.hpp"
#include "xieite/units/literals/angles.hpp"

int main() {
    xieite::geometry::Ray ray1({ 0.0, 0.0 }, { 1.0, 1.0 });
    xieite::geometry::Ray ray2({ 0.0, 0.0 }, 45_degrees);

    std::cout
        << std::boolalpha
        << (ray1 == ray2)
        << '\n';
}
```
Output:
```
true
```
