# [xieite](../../../../../xieite.md)\:\:[geometry](../../../../../geometry.md)\:\:[Segment<Number>](../../../segment.md)\:\:angle
Defined in header [<xieite/geometry/segment.hpp>](../../../../../../include/xieite/geometry/segment.hpp)

&nbsp;

## Description
Computes the angle of a segment in radians.

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
#include "xieite/geometry/segment.hpp"

int main() {
    std::println("{}", xieite::geometry::Segment({ 0.0, 0.0 }, { 1.0, 1.0 }).angle());
}
```
Possible output:
```
0.7853981633974483
```
