# [xieite](../../xieite.md)\:\:[strings](../../strings.md)\:\:trim\(\)
Defined in header [<xieite/strings/trim.hpp>](../../../include/xieite/strings/trim.hpp)

&nbsp;

## Description
Trims both the front and back of a string.

&nbsp;

## Synopsis
#### 1)
```cpp
[[nodiscard]] constexpr std::string_view trim(std::string_view string, char character) noexcept;
```
#### 2)
```cpp
[[nodiscard]] constexpr std::string_view trim(std::string_view string, std::string_view characters) noexcept;
```

&nbsp;

## Example
```cpp
#include <print>
#include "xieite/strings/trim.hpp"

int main() {
    std::println("{}", xieite::strings::trim("bababatananana", "ban"));
}
```
Output:
```
t
```
