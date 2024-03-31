# [xieite](../../xieite.md)\:\:[strings](../../strings.md)\:\:trimBack\(\)
Defined in header [<xieite/strings/trim_back.hpp>](../../../include/xieite/strings/trim_back.hpp)

&nbsp;

## Description
Trims the back of a string.

&nbsp;

## Synopsis
#### 1)
```cpp
[[nodiscard]] constexpr std::string_view trimBack(std::string_view string, char character) noexcept;
```
#### 2)
```cpp
[[nodiscard]] constexpr std::string_view trimBack(std::string_view string, std::string_view characters) noexcept;
```

&nbsp;

## Example
```cpp
#include <print>
#include "xieite/strings/trim_back.hpp"

int main() {
    std::println("{}", xieite::strings::trimBack("bababananana", "an"));
}
```
Output:
```
babab
```
