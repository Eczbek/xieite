# [xieite](../../xieite.md)\:\:[strings](../../strings.md)\:\:toRomanNumerals
Defined in header [<xieite/strings/to_roman_numerals.hpp>](../../../include/xieite/strings/to_roman_numerals.hpp)

&nbsp;

## Description
Converts a number to roman numerals.

&nbsp;

## Synopsis
#### 1)
```cpp
template<std::integral Integer>
[[nodiscard]] constexpr std::string toRomanNumerals(Integer value) noexcept;
```

&nbsp;

## Example
```cpp
#include <iostream>
#include "xieite/strings/to_roman_numerals.hpp"

int main() {
    std::cout << xieite::strings::toRomanNumerals(418) << '\n';
}
```
Output:
```
CDXVIII
```
