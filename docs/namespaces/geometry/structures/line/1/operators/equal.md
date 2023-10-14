# [xieite](../../../../../../xieite.md)\:\:[geometry](../../../../../../geometry.md)\:\:[Line](../../../../line.md)\:\:operator==
Defined in header [<xieite/geometry/line.hpp>](../../../../../../../include/xieite/geometry/line.hpp)

&nbsp;

## Description
Compares two lines.

&nbsp;

## Synopses
#### 1)
```cpp
[[nodiscard]] friend constexpr bool operator==(const xieite::geometry::Line& line1, const xieite::geometry::Line& line2) noexcept;
```

&nbsp;

## Example
```cpp
#include <iostream>
#include <xieite/geometry/line.hpp>
#include <xieite/geometry/point.hpp>
#include <xieite/units/literals/angles.hpp>

int main() {
    using namespace xieite::units::literals;

    xieite::geometry::Line line1({ 0.0, 0.0 }, { 1.0, 1.0 });
    xieite::geometry::Line line2({ 0.0, 0.0 }, 45_degrees);

    std::cout
        << std::boolalpha
        << (line1 == line2)
        << '\n';
}
```
Output:
```
true
```
