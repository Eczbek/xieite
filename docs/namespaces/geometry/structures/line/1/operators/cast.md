# [xieite](../../../../../../xieite.md)\:\:[geometry](../../../../../../geometry.md)\:\:[Line<Arithmetic>](../../../../line.md)\:\:operator typename\<\>\(\)
Defined in header [<xieite/geometry/line.hpp>](../../../../../../../include/xieite/geometry/line.hpp)

&nbsp;

## Description
Casts one line type to another.

&nbsp;

## Synopsis
#### 1)
```cpp
template<typename OtherArithmetic>
[[nodiscard]] explicit(false) constexpr operator xieite::geometry::Line<OtherArithmetic>() const noexcept;
```

&nbsp;

## Example
```cpp
#include <print>
#include "xieite/geometry/line.hpp"
#include "xieite/math/almost_equal_slope.hpp"

int main() {
    auto line1 = xieite::geometry::Line<double>({ 0.0, 0.0 }, { 1.0, 1.0 });
    float slope1 = static_cast<float>(line1.slope());

    xieite::geometry::Line<float> line2 = line1;
    float slope2 = line2.slope();

    std::println("{}", xieite::math::almostEqualSlope(slope1, slope2));
}
```
Possible output:
```
true
```
