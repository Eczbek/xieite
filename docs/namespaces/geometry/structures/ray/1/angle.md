# [xieite](../../../../../xieite.md)\:\:[geometry](../../../../../geometry.md)\:\:[Ray<Number>](../../../ray.md)\:\:angle
Defined in header [<xieite/geometry/ray.hpp>](../../../../../../include/xieite/geometry/ray.hpp)

&nbsp;

## Description
Computes the angle of a ray in radians.

&nbsp;

## Synopsis
#### 1)
```cpp
[[nodiscard]] constexpr std::conditional_t<std::floating_point<Number>, Number, double> angle() const noexcept;
```

&nbsp;

## Example
```cpp
#include <print>
#include "xieite/geometry/ray.hpp"

int main() {
    std::println("{}", xieite::geometry::Ray({ 0.0, 0.0 }, { 1.0, 1.0 }).angle());
}
```
Possible output:
```
0.7853981633974483
```
