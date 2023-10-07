# [xieite](../xieite.md)\:\:[strings](../strings.md)\:\:trimFront
Defined in header [<xieite/strings/trimFront.hpp>](../../include/xieite/strings/trimFront.hpp)

&nbsp;

## Description
Trims the front of a string.

&nbsp;

## Synopses
#### 1)
```cpp
[[nodiscard]] constexpr std::string_view trimFront(const std::string_view string, const char character) noexcept;
```
#### 2)
```cpp
[[nodiscard]] constexpr std::string_view trimFront(const std::string_view string, const std::string_view characters) noexcept;
```

&nbsp;

## Example
```cpp
#include <iostream>
#include <xieite/strings/trimFront.hpp>

int main() {
    std::cout << xieite::strings::trimFront("bababananana", "ab") << '\n';
}
```
Output:
```
nanana
```
