# [xieite](../../../../../xieite.md)\:\:[geometry](../../../../../geometry.md)\:\:[Polygon<Arithmetic_>](../../../polygon.md)\:\:perimeter\(\)
Defined in header [<xieite/geometry/polygon.hpp>](../../../../../../include/xieite/geometry/polygon.hpp)

&nbsp;

## Description
Computes the perimeter of a polygon.

&nbsp;

## Synopsis
#### 1)
```cpp
[[nodiscard]] constexpr double perimeter() const noexcept;
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

    std::println("{}", polygon.perimeter());
}
```
Output:
```
8
```
