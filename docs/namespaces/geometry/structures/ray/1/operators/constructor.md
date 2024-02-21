# [xieite](../../../../../../xieite.md)\:\:[geometry](../../../../../../geometry.md)\:\:[Ray](../../../../ray.md)\:\:Ray
Defined in header [<xieite/geometry/ray.hpp"](../../../../../../../include/xieite/geometry/ray.hpp)

&nbsp;

## Description
Constructs a `xieite::geometry::Ray`.

&nbsp;

## Synopses
#### 1)
```cpp
constexpr Ray(xieite::geometry::Point start, xieite::geometry::Point end) noexcept;
```
#### 2)
```cpp
constexpr Ray(xieite::geometry::Point start, double angle) noexcept;
```

&nbsp;

## Example
```cpp
#include <iostream>
#include "xieite/geometry/ray.hpp"
#include "xieite/geometry/point.hpp"
#include "xieite/geometry/contains_point.hpp"

int main() {
    ;

    std::cout
        << std::boolalpha
        << xieite::geometry::Ray({ 0.0, 0.0 }, { 1.0, 1.0 })
            .containsPoint({ -1.0, -1.0 })
        << '\n';
}
```
Output:
```
false
```
