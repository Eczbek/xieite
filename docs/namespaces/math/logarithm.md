# [xieite](../../xieite.md)\:\:[math](../../math.md)\:\:logarithm\(\)
Defined in header [<xieite/math/logarithm.hpp>](../../../include/xieite/math/logarithm.hpp)

&nbsp;

## Description
Takes the logarithm of a value in any base.

&nbsp;

## Synopsis
#### 1)
```cpp
template<xieite::concepts::Arithmetic Number>
[[nodiscard]] constexpr std::common_type_t<double, Number> logarithm(Number base, Number value) noexcept;
```

&nbsp;

## Example
```cpp
#include <print>
#include "xieite/math/logarithm.hpp"

int main() {
    std::println("{}", xieite::math::logarithm(5, 170));
}
```
Possible output:
```
3.1910509857959815
```
