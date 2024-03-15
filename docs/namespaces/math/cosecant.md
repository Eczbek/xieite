# [xieite](../../xieite.md)\:\:[math](../../math.md)\:\:cosecant\(\)
Defined in header [<xieite/math/cosecant.hpp>](../../../include/xieite/math/cosecant.hpp)

&nbsp;

## Description
Computes the cosecant of a value.

&nbsp;

## Synopsis
#### 1)
```cpp
template<xieite::concepts::Arithmetic Number>
[[nodiscard]] constexpr std::common_type_t<double, Number> cosecant(Number value) noexcept;
```

&nbsp;

## Example
```cpp
#include <print>
#include "xieite/literals/units.hpp"
#include "xieite/math/cosecant.hpp"

int main() {
    using namespace xieite::literals::units;

    std::println("{}", xieite::math::cosecant(45_degrees));
}
```
Possible output:
```
1.4142135623730951
```
