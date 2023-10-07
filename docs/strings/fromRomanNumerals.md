# [xieite](../xieite.md)\:\:[strings](../strings.md)\:\:fromRomanNumerals
Defined in header [<xieite/strings/fromRomanNumerals.hpp>](../../include/xieite/strings/fromRomanNumerals.hpp)

&nbsp;

## Description
Converts a number from roman numerals.

&nbsp;

## Synopses
#### 1)
```cpp
template<std::integral Integer = int>
[[nodiscard]] constexpr Integer fromRomanNumerals(const std::string_view value) noexcept;
```

&nbsp;

## Example
```cpp
#include <iostream>
#include <xieite/strings/fromRomanNumerals.hpp>

int main() {
    std::cout << xieite::strings::fromRomanNumerals("CDXVIII") << '\n';
}
```
Output:
```
418
```
