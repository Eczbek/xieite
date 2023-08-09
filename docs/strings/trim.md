# [xieite](../xieite.md)\:\:[strings](../strings.md)\:\:trim
Defined in header [<xieite/strings/trim.hpp>](../../include/xieite/strings/trim.hpp)

&nbsp;

## Description
Trims both the front and back of a string.

&nbsp;

## Synopses
#### 1)
```cpp
constexpr std::string trim(const std::string& string, char character) noexcept;
```
#### 2)
```cpp
template<xieite::concepts::RangeOf<char> CharacterRange>
constexpr std::string trim(const std::string& string, const CharacterRange& characters) noexcept;
```

&nbsp;

## Example
```cpp
#include <iostream>
#include <vector>
#include <xieite/strings/trim.hpp>

int main() {
    std::vector<char> characters {
        'b',
        'a',
        'n'
    };

    std::cout << xieite::strings::trim("bababatananana", characters) << '\n';
}
```
Output:
```
t
```
