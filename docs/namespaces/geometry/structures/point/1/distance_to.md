# [xieite](../../../../../xieite.md)\:\:[geometry](../../../../../geometry.md)\:\:[Point<Arithmetic_>](../../../point.md)\:\:distanceTo\(\)
Defined in header [<xieite/geometry/point.hpp>](../../../../../../include/xieite/geometry/point.hpp)

&nbsp;

## Description
Computes the distance between two points.

&nbsp;

## Synopsis
#### 1)
```cpp
[[nodiscard]] constexpr std::conditional_t<std::floating_point<Arithmetic_>, Arithmetic_, double> distanceTo(xieite::geometry::Point<Arithmetic_> point) const noexcept;
```

&nbsp;

## Example
```cpp
#include <print>
#include "xieite/geometry/point.hpp"

int main() {
    std::println("{}", xieite::geometry::Point(0.0, 0.0).distanceTo({ 1.0, 1.0 }));
}
```
Possible output:
```
1.4142135623730951
```
