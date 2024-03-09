# [xieite](../../../../../xieite.md)\:\:[geometry](../../../../../geometry.md)\:\:[Segment<Number>](../../../segment.md)\:\:length
Defined in header [<xieite/geometry/segment.hpp>](../../../../../../include/xieite/geometry/segment.hpp)

&nbsp;

## Description
Computes the distance between the start and end of a segment.

&nbsp;

## Synopsis
#### 1)
```cpp
[[nodiscard]] constexpr std::conditional_t<std::floating_point<Number>, Number, double> length() const noexcept;
```

&nbsp;

## Example
```cpp
#include <print>
#include "xieite/geometry/segment.hpp"

int main() {
    std::println("{}", xieite::geometry::Segment({ 0.0, 0.0 }, { 1.0, 1.0 }).length());
}
```
Possible output:
```
1.4142135623730951
```
