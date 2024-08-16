# [xieite](../../../../../../xieite.md)\:\:[geometry](../../../../../../geometry.md)\:\:[Polygon<Arithmetic>](../../../../polygon.md)\:\:operator typename\<\>\(\)
Defined in header [<xieite/geometry/polygon.hpp>](../../../../../../../include/xieite/geometry/polygon.hpp)

&nbsp;

## Description
Casts one polygon type to another.

&nbsp;

## Synopsis
#### 1)
```cpp
template<typename OtherArithmetic>
[[nodiscard]] explicit(false) constexpr operator xieite::geometry::Polygon<OtherArithmetic>() const noexcept;
```

&nbsp;

## Example
```cpp
#include <print>
#include "xieite/geometry/polygon.hpp"

int main() {
    auto polygon1 = xieite::geometry::Polygon<double>({
        { 1.0, 0.0 },
        { 2.0, 1.0 },
        { 1.0, 2.0 },
        { 0.0, 1.0 }
    });

    xieite::geometry::Polygon<float> polygon2 = polygon1;

    for (auto point : polygon2.points) {
        std::println("({}, {})", point.x, point.y);
    }
}
```
Possible output:
```
(1, 0)
(2, 1)
(1, 2)
(0, 1)
```
