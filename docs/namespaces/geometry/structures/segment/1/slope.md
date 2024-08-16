# [xieite](../../../../../xieite.md)\:\:[geometry](../../../../../geometry.md)\:\:[Segment<Arithmetic>](../../../segment.md)\:\:slope\(\)
Defined in header [<xieite/geometry/segment.hpp>](../../../../../../include/xieite/geometry/segment.hpp)

&nbsp;

## Description
Computes the slope of a segment.

&nbsp;

## Synopsis
#### 1)
```cpp
[[nodiscard]] constexpr std::conditional_t<std::floating_point<Arithmetic>, Arithmetic, double> slope() const noexcept;
```

&nbsp;

## Example
```cpp
#include <print>
#include "xieite/geometry/segment.hpp"

int main() {
    std::println("{}", xieite::geometry::Segment({ 0.0, 0.0 }, { 1.0, 1.0 }).slope());
}
```
Possible output:
```
1
```
