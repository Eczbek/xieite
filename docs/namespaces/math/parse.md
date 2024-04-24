# [xieite](../../xieite.md)\:\:[math](../../math.md)\:\:parse\(\)
Defined in header [<xieite/math/parse.hpp>](../../../include/xieite/math/parse.hpp)

&nbsp;

## Description
Parses an number string in any radix. Allows negative radices. Is case-sensitive.

&nbsp;

## Synopsis
#### 1)
```cpp
template<xieite::concepts::Arithmetic Number>
[[nodiscard]] constexpr Number parse(std::string_view value, std::conditional_t<std::floating_point<Number>, xieite::math::SignedSize, Number> radix = 10, xieite::strings::NumberComponents components = xieite::strings::NumberComponents()) noexcept;
```

&nbsp;

## Example
```cpp
#include <print>
#include "xieite/math/parse.hpp"

int main() {
    std::println("{}", xieite::math::parse<int>("G4H3", 21));
}
```
Output:
```
150300
```
