# [xieite](../../xieite.md)\:\:[strings](../../strings.md)\:\:validNumber
Defined in header [<xieite/strings/valid_number.hpp"](../../../include/xieite/strings/valid_number.hpp)

&nbsp;

## Description
Checks if a string can be parsed a number from.

&nbsp;

## Synopses
#### 1)
```cpp
template<xieite::concepts::Arithmetic Number>
[[nodiscard]] constexpr bool validNumber(std::string_view value) noexcept;
```

&nbsp;

## Example
```cpp
#include <iostream>
#include "xieite/strings/valid_number.hpp"

int main() {
    std::cout
        << std::boolalpha
        << xieite::strings::validNumber("3.14159") << '\n'
        << xieite::strings::validNumber("test") << '\n';
}
```
Output:
```
true
false
```
