# [xieite](../xieite.md)\:\:[strings](../strings.md)\:\:toRomanNumerals
Defined in header [<xieite/strings/toRomanNumerals.hpp>](../../include/xieite/strings/toRomanNumerals.hpp)

&nbsp;

## Description
Converts a number to roman numerals.

&nbsp;

## Synopses
#### 1)
```cpp
template<std::integral Integer>
[[nodiscard]] constexpr std::string toRomanNumerals(const Integer value) noexcept;
```

&nbsp;

## Example
```cpp
#include <iostream>
#include <xieite/strings/toRomanNumerals.hpp>

int main() {
    std::cout << xieite::strings::toRomanNumerals(418) << '\n';
}
```
Output:
```
CDXVIII
```
