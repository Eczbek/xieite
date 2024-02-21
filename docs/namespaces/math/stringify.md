# [xieite](../../xieite.md)\:\:[math](../../math.md)\:\:stringify
Defined in header [<xieite/math/stringify.hpp"](../../../include/xieite/math/stringify.hpp)

&nbsp;

## Description
Stringifies a number in any base. Allows negative bases.

&nbsp;

## Synopses
#### 1)
```cpp
template<xieite::concepts::Arithmetic Number>
[[nodiscard]] constexpr std::string stringify(Number value, std::conditional_t<std::integral<Number>, Number, std::make_signed_t<std::size_t>> radix = 10, const xieite::math::IntegerStringComponents& components = xieite::math::IntegerStringComponents()) noexcept;
```

&nbsp;

## Example
```cpp
#include <iostream>
#include "xieite/math/stringify.hpp"

int main() {
    std::cout << xieite::math::stringify(13, 2) << '\n';
}
```
Output:
```
1101
```
