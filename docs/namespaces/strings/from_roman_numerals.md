# [xieite](../../xieite.md)\:\:[strings](../../strings.md)\:\:fromRomanNumerals\<\>\(\)
Defined in fragment [xieite:strings.fromRomanNumerals](../../../src/strings/from_roman_numerals.cpp)

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
import std;
import xieite;

int main() {
    std::println("{}", xieite::strings::fromRomanNumerals("CDXVIII"));
}
```
Output:
```
418
```
