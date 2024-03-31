# [xieite](../../xieite.md)\:\:[strings](../../strings.md)\:\:fromRomanNumerals\(\)
Defined in header [<xieite/strings/from_roman_numerals.hpp>](../../../include/xieite/strings/from_roman_numerals.hpp)

&nbsp;

## Description
Converts roman numerals to a number.

&nbsp;

## Synopsis
#### 1)
```cpp
template<std::integral Integral = int>
[[nodiscard]] constexpr Integral fromRomanNumerals(const std::string_view value) noexcept;
```

&nbsp;

## Example
```cpp
#include <print>
#include "xieite/strings/from_roman_numerals.hpp"

int main() {
    std::println("{}", xieite::strings::fromRomanNumerals("CDXVIII"));
}
```
Output:
```
418
```
