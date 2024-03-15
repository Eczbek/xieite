# [xieite](../../xieite.md)\:\:[math](../../math.md)\:\:secant\(\)
Defined in header [<xieite/math/secant.hpp>](../../../include/xieite/math/secant.hpp)

&nbsp;

## Description
Computes the secant of a value.

&nbsp;

## Synopsis
#### 1)
```cpp
template<xieite::concepts::Arithmetic Number>
[[nodiscard]] constexpr std::common_type_t<double, Number> secant(Number value) noexcept;
```

&nbsp;

## Example
```cpp
#include <print>
#include "xieite/literals/units.hpp"
#include "xieite/math/secant.hpp"

int main() {
    using namespace xieite::literals::units;

    std::println("{}", xieite::math::secant(45_degrees));
}
```
Possible output:
```
1.414213562373095
```
