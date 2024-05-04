# [xieite](../../../../../../xieite.md)\:\:[geometry](../../../../../../geometry.md)\:\:[Segment<Arithmetic_>](../../../../segment.md)\:\:operator typename\<\>\(\)
Defined in header [<xieite/geometry/segment.hpp>](../../../../../../../include/xieite/geometry/segment.hpp)

&nbsp;

## Description
Casts one segment type to another.

&nbsp;

## Synopsis
#### 1)
```cpp
template<typename OtherArithmetic_>
[[nodiscard]] constexpr operator xieite::geometry::Segment<OtherArithmetic_>() const noexcept;
```

&nbsp;

## Example
```cpp
#include <print>
#include "xieite/geometry/point.hpp"

int main() {
    auto segment1 = xieite::geometry::Segment<double>({ 0.0, 0.0 }, { 3.0, 4.0 });

    xieite::geometry::Segment<float> segment2 = segment1;

    std::println("{}", segment1.slope() == segment2.slope());
}
```
Output:
```
true
```
