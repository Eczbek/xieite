# [xieite](../../xieite.md)\:\:[strings](../../strings.md)\:\:toRomanNumerals
Defined in header [<xieite/strings/to_roman_numerals.hpp>](../../../include/xieite/strings/to_roman_numerals.hpp)

&nbsp;

## Description
Converts a number to roman numerals.

&nbsp;

## Synopsis
#### 1)
```cpp
template<std::integral Integral>
[[nodiscard]] constexpr std::string toRomanNumerals(Integral value) noexcept;
```

&nbsp;

## Example
```cpp
#include <print>
#include "xieite/strings/to_roman_numerals.hpp"

int main() {
    std::println("{}", xieite::strings::toRomanNumerals(418));
}
```
Output:
```
CDXVIII
```
