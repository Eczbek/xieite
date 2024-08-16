# [xieite](../../xieite.md)\:\:[math](../../math.md)\:\:tangent\<\>\(\)
Defined in header [<xieite/math/tangent.hpp>](../../../include/xieite/math/cotagent.hpp)

&nbsp;

## Description
Computes the tangent of an optionally inverse, hyperbolic, or reciprocal theta.

&nbsp;

## Synopsis
#### 1)
```cpp
template<xieite::concepts::Arithmetic Arithmetic, xieite::concepts::Arithmetic Result = std::common_type_t<double, Arithmetic>>
[[nodiscard]] constexpr Result tangent(Arithmetic theta, bool inverse, bool hyperbolic, bool reciprocal) noexcept;
```

&nbsp;

## Example
```cpp
#include <print>
#include "xieite/literals/units.hpp"
#include "xieite/math/tangent.hpp"

int main() {
    using namespace xieite::literals::units;

    std::println("{}", xieite::math::tangent(45_degrees, true, true, true));
}
```
Possible output:
```
0.9440141363689468
```
