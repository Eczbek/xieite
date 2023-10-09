# [xieite](../../xieite.md)\:\:[strings](../../strings.md)\:\:trimBack
Defined in header [<xieite/strings/trim_back.hpp>](../../../include/xieite/strings/trim_back.hpp)

&nbsp;

## Description
Trims the back of a string.

&nbsp;

## Synopses
#### 1)
```cpp
[[nodiscard]] constexpr std::string_view trimBack(const std::string_view string, const char character) noexcept;
```
#### 2)
```cpp
[[nodiscard]] constexpr std::string_view trimBack(const std::string_view string, const std::string_view characters) noexcept;
```

&nbsp;

## Example
```cpp
#include <iostream>
#include <xieite/strings/trim_back.hpp>

int main() {
    std::cout << xieite::strings::trimBack("bababananana", "an") << '\n';
}
```
Output:
```
babab
```
