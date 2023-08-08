# [xieite](../xieite.md)\:\:[strings](../strings.md)\:\:trimBack
Defined in header [<xieite/strings/trimBack.hpp>](../../include/xieite/strings/trimBack.hpp)

&nbsp;

## Description
Trims the back of a string

&nbsp;

## Synopses

&nbsp;

```cpp
[[nodiscard]]
constexpr std::string trimBack(const std::string& string, char character) noexcept;
```
#### Function parameters
- `string` - A `std::string` constant reference
- `character` - A `char`
#### Return type
- `std::string`

&nbsp;

```cpp
template<xieite::concepts::RangeOf<char> CharacterRange>
[[nodiscard]]
constexpr std::string trimBack(const std::string& string, const CharacterRange& characters) noexcept;
```
#### Template parameters
- `CharacterRange` - A type satisfying `xieite::concepts::RangeOf` of `char`
#### Function parameters
- `string` - A `std::string` constant reference
- `characters` - A constant `CharacterRange` reference
#### Return type
- `std::string`

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
