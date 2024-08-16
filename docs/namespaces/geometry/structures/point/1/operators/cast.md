# [xieite](../../../../../../xieite.md)\:\:[geometry](../../../../../../geometry.md)\:\:[Point<Arithmetic>](../../../../point.md)\:\:operator typename\<\>\(\)
Defined in header [<xieite/geometry/point.hpp>](../../../../../../../include/xieite/geometry/point.hpp)

&nbsp;

## Description
Casts one point type to another.

&nbsp;

## Synopsis
#### 1)
```cpp
template<typename OtherArithmetic>
[[nodiscard]] explicit(false) constexpr operator xieite::geometry::Point<OtherArithmetic>() const noexcept;
```

&nbsp;

## Example
```cpp
#include <print>
#include "xieite/geometry/point.hpp"

int main() {
    auto point1 = xieite::geometry::Point<double>(3.0, 4.0);

    xieite::geometry::Point<float> point2 = point1;

    std::println("({}, {})", point2.x, point2.y);
}
```
Output:
```
(3, 4)
```
