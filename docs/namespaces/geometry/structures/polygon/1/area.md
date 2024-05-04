# [xieite](../../../../../xieite.md)\:\:[geometry](../../../../../geometry.md)\:\:[Polygon<Arithmetic_>](../../../polygon.md)\:\:area\(\)
Defined in header [<xieite/geometry/polygon.hpp>](../../../../../../include/xieite/geometry/polygon.hpp)

&nbsp;

## Description
Computes the area of a polygon.

&nbsp;

## Synopsis
#### 1)
```cpp
[[nodiscard]] constexpr double area() const noexcept;
```

&nbsp;

## Example
```cpp
#include <print>
#include "xieite/geometry/polygon.hpp"

int main() {
    auto polygon = xieite::geometry::Polygon({
        { 0.0, 0.0 },
        { 2.0, 0.0 },
        { 2.0, 2.0 },
        { 0.0, 2.0 }
    });

    std::println("{}", polygon.area());
}
```
Possible output:
```
4
```
