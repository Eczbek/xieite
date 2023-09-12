# [xieite](../../../../xieite.md)\:\:[geometry](../../../../geometry.md)\:\:[Ray](../../../Ray.md)\:\:operator==
Defined in header [<xieite/geometry/Ray.hpp>](../../../../../include/xieite/geometry/Ray.hpp)

&nbsp;

## Description
Compares two rays.

&nbsp;

## Synopses
#### 1)
```cpp
friend constexpr bool operator==(const xieite::geometry::Ray& ray1, const xieite::geometry::Ray& ray2) noexcept;
```

&nbsp;

## Example
```cpp
#include <iostream>
#include <xieite/geometry/Ray.hpp>
#include <xieite/geometry/Point.hpp>
#include <xieite/math/toRadians.hpp>

int main() {
    xieite::geometry::Ray ray1({ 0.0, 0.0 }, { 1.0, 1.0 });
    xieite::geometry::Ray ray2({ 0.0, 0.0 }, xieite::math::toRadians(45.0));

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
