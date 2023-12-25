# [xieite](../../xieite.md)\:\:[strings](../../strings.md)\:\:parseNumber
Defined in header [<xieite/strings/parse_number.hpp>](../../../include/xieite/strings/parse_number.hpp)

&nbsp;

## Description
Parses a number from a string.

&nbsp;

## Synopses
#### 1)
```cpp
template<xieite::concepts::Arithmetic Number>
[[nodiscard]] constexpr Number parseNumber(std::string_view value) noexcept;
```

&nbsp;

## Example
```cpp
#include <iostream>
#include <xieite/strings/parse_number.hpp>

int main() {
    std::cout
        << std::boolalpha
        << xieite::strings::parseNumber<int>("+20") << '\n'
        << xieite::strings::parseNumber<double>("3.14159e-2") << '\n';
}
```
Output:
```
20
0.0314159
```
