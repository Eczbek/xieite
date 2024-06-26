# [xieite](../../xieite.md)\:\:[math](../../math.md)\:\:stringify\<\>\(\)
Defined in header [<xieite/math/stringify.hpp>](../../../include/xieite/math/stringify.hpp)

&nbsp;

## Description
Stringifies a number in any radix. Allows negative radices.

&nbsp;

## Synopsis
#### 1)
```cpp
template<xieite::concepts::Arithmetic Arithmetic_>
[[nodiscard]] constexpr std::string stringify(Arithmetic_ value, std::conditional_t<std::floating_point<Arithmetic_>, xieite::math::SignedSize, Arithmetic_> radix = 10, xieite::strings::NumberComponents components = xieite::strings::NumberComponents()) noexcept;
```

&nbsp;

## Example
```cpp
#include <print>
#include "xieite/math/stringify.hpp"

int main() {
    std::println("{}", xieite::math::stringify(13, 2));
}
```
Output:
```
1101
```
