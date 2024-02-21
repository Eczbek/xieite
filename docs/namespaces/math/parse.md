# [xieite](../../xieite.md)\:\:[math](../../math.md)\:\:parse
Defined in header [<xieite/math/parse.hpp"](../../../include/xieite/math/parse.hpp)

&nbsp;

## Description
Parses an number string in any base. Allows negative bases.

&nbsp;

## Synopses
#### 1)
```cpp
template<xieite::concepts::Arithmetic Number>
[[nodiscard]] constexpr Number parse(std::string_view value, std::conditional_t<std::integral<Number>, Number, std::make_signed_t<std::size_t>> radix = 10, const xieite::math::IntegerStringComponents& components = xieite::math::IntegerStringComponents()) noexcept;
```

&nbsp;

## Example
```cpp
#include <iostream>
#include "xieite/math/parse.hpp"

int main() {
    std::cout << xieite::math::parse<int>("g4h3", 21) << '\n';
}
```
Output:
```
150300
```
