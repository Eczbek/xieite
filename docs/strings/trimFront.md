# [xieite](../xieite.md)\:\:[strings](../strings.md)\:\:trimFront
Defined in header [<xieite/strings/trimFront.hpp>](../../include/xieite/strings/trimFront.hpp)

&nbsp;

## Description
Trims the front of a string.

&nbsp;

## Synopses
#### 1)
```cpp
constexpr std::string trimFront(const std::string& string, char character) noexcept;
```
#### 2)
```cpp
template<xieite::concepts::RangeOf<char> CharacterRange>
constexpr std::string trimFront(const std::string& string, const CharacterRange& characters) noexcept;
```

&nbsp;

## Example
```cpp
#include <iostream>
#include <vector>
#include <xieite/strings/trimFront.hpp>

int main() {
    std::vector<char> characters {
        'a',
        'b'
    };

    std::cout << xieite::strings::trimFront("bababananana", characters) << '\n';
}
```
Output:
```
nanana
```
