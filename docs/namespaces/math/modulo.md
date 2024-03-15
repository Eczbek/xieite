# [xieite](../../xieite.md)\:\:[math](../../math.md)\:\:modulo\(\)
Defined in header [<xieite/math/modulo.hpp>](../../../include/xieite/math/modulo.hpp)

&nbsp;

## Description
Computes modulus better.

&nbsp;

## Synopsis
#### 1)
```cpp
template<xieite::concepts::Arithmetic Number>
[[nodiscard]] constexpr Number modulo(Number dividend, Number divisor) noexcept;
```

&nbsp;

## Example
```cpp
#include <print>
#include "xieite/math/modulo.hpp"

int main() {
    std::println("{}", xieite::math::modulo(-21, 4));
}
```
Output:
```
3
```
