# [xieite](../xieite.md)\:\:[math](../math.md)\:\:fromBase
Defined in header [<xieite/math/fromBase.hpp>](../../include/xieite/math/fromBase.hpp)

&nbsp;

## Description
Converts an integer string to base 10. Allows negative bases.

&nbsp;

## Synopses
#### 1)
```cpp
template<std::integral Integer = int>
constexpr Integer fromBase(const xieite::math::Base& base, std::string_view value) noexcept;
```

&nbsp;

## Example
```cpp
#include <iostream>
#include <xieite/math/Base.hpp>
#include <xieite/math/fromBase.hpp>

int main() {
    std::cout << xieite::math::fromBase(xieite::math::Base(21), "g4h3") << '\n';
}
```
Output:
```
150300
```
