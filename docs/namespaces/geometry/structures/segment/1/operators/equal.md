# [xieite](../../../../../../xieite.md)\:\:[geometry](../../../../../../geometry.md)\:\:[Segment<Arithmetic_>](../../../../segment.md)\:\:operator==\(\)
Defined in header [<xieite/geometry/segment.hpp>](../../../../../../../include/xieite/geometry/segment.hpp)

&nbsp;

## Description
Compares two segments.

&nbsp;

## Synopsis
#### 1)
```cpp
[[nodiscard]] friend constexpr bool operator==(const xieite::geometry::Segment<Arithmetic_>& segment1, const xieite::geometry::Segment<Arithmetic_>& segment2) noexcept;
```

&nbsp;

## Example
```cpp
#include <print>
#include "xieite/geometry/point.hpp"

int main() {
    auto segment1 = xieite::geometry::Segment({ 0.0, 0.0 }, { 3.0, 4.0 });
    auto segment2 = xieite::geometry::Segment({ 3.0, 4.0 }, { 0.0, 0.0 });

    std::println("{}", segment1 == segment2);
}
```
Output:
```
true
```
