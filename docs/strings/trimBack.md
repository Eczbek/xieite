# [xieite](../xieite.md)\:\:[strings](../strings.md)\:\:trimBack
Defined in header [<xieite/strings/trimBack.hpp>](../../include/xieite/strings/trimBack.hpp)

&nbsp;

## Description
Trims the back of a string.

&nbsp;

## Synopses
#### 1)
```cpp
[[nodiscard]]
constexpr std::string trimBack(const std::string& string, char character) noexcept;
```
#### 2)
```cpp
template<xieite::concepts::RangeOf<char> CharacterRange>
[[nodiscard]]
constexpr std::string trimBack(const std::string& string, const CharacterRange& characters) noexcept;
```

&nbsp;

## Example
```cpp
#include <iostream>
#include <vector>
#include <xieite/strings/trimBack.hpp>

int main() {
    std::vector<char> characters {
        'a',
        'n'
    };

    std::cout << xieite::strings::trimBack("bababananana", characters) << '\n';
}
```
Output:
```
babab
```
