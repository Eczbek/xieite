# [xieite](../../xieite.md)\:\:[math](../../math.md)\:\:cotangent\(\)
Defined in header [<xieite/math/cotangent.hpp>](../../../include/xieite/math/cotagent.hpp)

&nbsp;

## Description
Computes the cotangent of a value.

&nbsp;

## Synopsis
#### 1)
```cpp
template<xieite::concepts::Arithmetic Number>
[[nodiscard]] constexpr std::common_type_t<double, Number> cotangent(Number value) noexcept;
```

&nbsp;

## Example
```cpp
#include <print>
#include "xieite/literals/units.hpp"
#include "xieite/math/cotangent.hpp"

int main() {
    using namespace xieite::literals::units;

    std::println("{}", xieite::math::cotangent(45_degrees));
}
```
Output (rounded):
```
1
```
