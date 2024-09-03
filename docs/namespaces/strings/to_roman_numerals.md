# [xieite](../../xieite.md)\:\:[strings](../../strings.md)\:\:toRomanNumerals\(\)
Defined in fragment [xieite:strings.toRomanNumerals](../../../src/strings/to_roman_numerals.cpp)

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
import std;
import xieite;

int main() {
    std::println("{}", xieite::strings::toRomanNumerals(418));
}
```
Output:
```
CDXVIII
```
