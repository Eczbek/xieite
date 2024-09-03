# [xieite](../../xieite.md)\:\:[strings](../../strings.md)\:\:radiotelephonySpellingAlphabet
Defined in fragment [xieite:strings.radiotelephonySpellingAlphabet](../../../src/strings/radiotelephony_spelling_alphabet.cpp)

&nbsp;

## Description
Defines the radiotelephony spelling alphabet. See definition for specifics.

&nbsp;

## Synopsis
#### 1)
```cpp
inline constexpr std::array<std::string_view, /* size */> radiotelephonySpellingAlphabet = /* ... */;
```

&nbsp;

## Example
```cpp
import std;
import xieite;

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
