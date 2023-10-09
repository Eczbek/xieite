# [xieite](../../xieite.md)\:\:[math](../../math.md)\:\:fromBase
Defined in header [<xieite/math/from_base.hpp>](../../../include/xieite/math/from_base.hpp)

&nbsp;

## Description
Converts an integer string to base 10. Allows negative bases.

&nbsp;

## Synopses
#### 1)
```cpp
template<std::integral Integer = int>
[[nodiscard]] constexpr Integer fromBase(std::string_view value, int radix, std::string_view digits = "0123456789abcdefghijklmnopqrstuvwxyz", char negativeSign = '-', bool caseSensitive = false) noexcept;
```

&nbsp;

## Example
```cpp
#include <iostream>
#include <xieite/math/Base.hpp>
#include <xieite/math/from_base.hpp>

int main() {
    std::cout << xieite::math::fromBase("g4h3", 21) << '\n';
}
```
Output:
```
150300
```
