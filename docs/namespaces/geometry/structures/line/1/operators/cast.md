# [xieite](../../../../../../xieite.md)\:\:[geometry](../../../../../../geometry.md)\:\:[Line<Number>](../../../../line.md)\:\:operator typename
Defined in header [<xieite/geometry/line.hpp>](../../../../../../../include/xieite/geometry/line.hpp)

&nbsp;

## Description
Casts one line type to another.

&nbsp;

## Synopsis
#### 1)
```cpp
template<typename OtherNumber>
[[nodiscard]] constexpr operator xieite::geometry::Line<OtherNumber>() const noexcept;
```

&nbsp;

## Example
```cpp
#include <print>
#include "xieite/geometry/line.hpp"

int main() {
    auto line1 = xieite::geometry::Line<double>({ 0.0, 0.0 }, { 1.0, 1.0 });

    xieite::geometry::Line<float> line2 = line1;

    std::println("{}", line1.slope() == line2.slope());
}
```
Output:
```
true
```
