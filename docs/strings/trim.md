# [xieite](../xieite.md)\:\:[strings](../strings.md)\:\:trim
Defined in header [<xieite/strings/trim.hpp>](../../include/xieite/strings/trim.hpp)

&nbsp;

## Description
Trims both the front and back of a string.

&nbsp;

## Synopses
#### 1)
```cpp
[[nodiscard]] constexpr std::string_view trim(const std::string_view string, const char character) noexcept;
```
#### 2)
```cpp
[[nodiscard]] constexpr std::string_view trim(const std::string_view string, const std::string_view characters) noexcept;
```

&nbsp;

## Example
```cpp
#include <iostream>
#include <xieite/strings/trim.hpp>

int main() {
    std::cout << xieite::strings::trim("bababatananana", "ban") << '\n';
}
```
Output:
```
t
```
