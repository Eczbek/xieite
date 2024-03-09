# [xieite](../../../../../../xieite.md)\:\:[geometry](../../../../../../geometry.md)\:\:[Line<Number>](../../../../line.md)\:\:operator==
Defined in header [<xieite/geometry/line.hpp>](../../../../../../../include/xieite/geometry/line.hpp)

&nbsp;

## Description
Compares two lines.

&nbsp;

## Synopsis
#### 1)
```cpp
[[nodiscard]] friend constexpr bool operator==(const xieite::geometry::Line<Number>& line1, const xieite::geometry::Line<Number>& line2) noexcept;
```

&nbsp;

## Example
```cpp
#include <print>
#include "xieite/geometry/line.hpp"
#include "xieite/literals/units.hpp"

int main() {
    using namespace xieite::literals::units;

    auto line1 = xieite::geometry::Line({ 0.0, 0.0 }, { 1.0, 1.0 });
    auto line2 = xieite::geometry::Line({ 0.0, 0.0 }, 45_degrees);

    std::println("{}", line1 == line2);
}
```
Output:
```
true
```
