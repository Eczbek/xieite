# [xieite](../../../../../xieite.md)\:\:[geometry](../../../../../geometry.md)\:\:[Line<Arithmetic_>](../../../line.md)\:\:angle\(\)
Defined in header [<xieite/geometry/line.hpp>](../../../../../../include/xieite/geometry/line.hpp)

&nbsp;

## Description
Computes the angle of a line in radians.

&nbsp;

## Synopsis
#### 1)
```cpp
[[nodiscard]] constexpr double angle() const noexcept;
```

&nbsp;

## Example
```cpp
#include <print>
#include "xieite/geometry/line.hpp"

int main() {
    std::println("{}", xieite::geometry::Line({ 0.0, 0.0 }, { 1.0, 1.0 }).angle());
}
```
Possible output:
```
0.7853981633974483
```
