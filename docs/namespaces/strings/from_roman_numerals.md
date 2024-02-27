# [xieite](../../xieite.md)\:\:[strings](../../strings.md)\:\:fromRomanNumerals
Defined in header [<xieite/strings/from_roman_numerals.hpp>](../../../include/xieite/strings/from_roman_numerals.hpp)

&nbsp;

## Description
Converts a number from roman numerals.

&nbsp;

## Synopsis
#### 1)
```cpp
template<std::integral Integer = int>
[[nodiscard]] constexpr Integer fromRomanNumerals(const std::string_view value) noexcept;
```

&nbsp;

## Example
```cpp
#include <iostream>
#include "xieite/strings/from_roman_numerals.hpp"

int main() {
    std::cout << xieite::strings::fromRomanNumerals("CDXVIII") << '\n';
}
```
Output:
```
418
```
