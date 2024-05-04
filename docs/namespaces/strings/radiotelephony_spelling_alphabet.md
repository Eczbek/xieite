# [xieite](../../xieite.md)\:\:[strings](../../strings.md)\:\:radiotelephonySpellingAlphabet
Defined in header [<xieite/strings/radiotelephony_spelling_alphabet.hpp>](../../../include/xieite/strings/radiotelephony_spelling_alphabet.hpp)

&nbsp;

## Description
Defines the radiotelephony spelling alphabet. See header file for the exact definitions.

&nbsp;

## Synopsis
#### 1)
```cpp
inline constexpr auto radiotelephonySpellingAlphabet = /* std::array<std::string_view, N> */;
```

&nbsp;

## Example
```cpp
#include <print>
#include <string>
#include "xieite/strings/radiotelephony_spelling_alphabet.hpp"

int main() {
    for (char character : std::string("Hello, world!")) {
        std::println("{}", xieite::strings::radiotelephonySpellingAlphabet[character]);
    }
}
```
Output:
```
Hotel
Echo
Lima
Lima
Oscar
Comma

Whiskey
Oscar
Romeo
Lima
Delta
Exclamation Mark
```
