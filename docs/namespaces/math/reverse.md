# [xieite](../../xieite.md)\:\:[math](../../math.md)\:\:reverse\(\)
Defined in header [<xieite/math/reverse.hpp>](../../../include/xieite/math/reverse.hpp)

&nbsp;

## Description
Reverses the digits of an integral of any radix. Allows negative radices.

&nbsp;

## Synopsis
#### 1)
```cpp
template<std::integral Integral>
[[nodiscard]] constexpr Integral reverse(Integral value, Integral radix = 10) noexcept;
```

&nbsp;

## Example
```cpp
#include <print>
#include "xieite/math/reverse.hpp"

int main() {
    std::println("{}", xieite::math::reverse(12345));
}
```
Output:
```
54321
```
