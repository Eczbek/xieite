# [xieite](../../../../../xieite.md)\:\:[geometry](../../../../../geometry.md)\:\:[Point<Arithmetic>](../../../point.md)\:\:angleTo\(\)
Defined in header [<xieite/geometry/point.hpp>](../../../../../../include/xieite/geometry/point.hpp)

&nbsp;

## Description
Computes the angle between two points.

&nbsp;

## Synopsis
#### 1)
```cpp
[[nodiscard]] constexpr std::conditional_t<std::floating_point<Arithmetic>, Arithmetic, double> angleTo(xieite::geometry::Point<Arithmetic> point) const noexcept;
```

&nbsp;

## Example
```cpp
#include <print>
#include "xieite/geometry/point.hpp"

int main() {
    std::println("{}", xieite::geometry::Point(0.0, 0.0).angleTo({ 1.0, 1.0 }));
}
```
Possible output:
```
0.7853981633974483
```
