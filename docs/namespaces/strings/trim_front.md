# [xieite](../../xieite.md)\:\:[strings](../../strings.md)\:\:trimFront
Defined in header [<xieite/strings/trim_front.hpp>](../../../include/xieite/strings/trim_front.hpp)

&nbsp;

## Description
Trims the front of a string.

&nbsp;

## Synopses
#### 1)
```cpp
[[nodiscard]] constexpr std::string_view trimFront(std::string_view string, char character) noexcept;
```
#### 2)
```cpp
[[nodiscard]] constexpr std::string_view trimFront(std::string_view string, std::string_view characters) noexcept;
```

&nbsp;

## Example
```cpp
#include <iostream>
#include <xieite/strings/trim_front.hpp>

int main() {
    std::cout << xieite::strings::trimFront("bababananana", "ab") << '\n';
}
```
Output:
```
nanana
```
