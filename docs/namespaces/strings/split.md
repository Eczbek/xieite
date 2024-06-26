# [xieite](../../xieite.md)\:\:[strings](../../strings.md)\:\:split\(\)
Defined in header [<xieite/strings/split.hpp>](../../../include/xieite/strings/split.hpp)

&nbsp;

## Description
Splits a string by a delimiter.

&nbsp;

## Synopsis
#### 1)
```cpp
[[nodiscard]] constexpr std::vector<std::string_view> split(std::string_view string, std::string_view delimiter, bool discardEmpty = false) noexcept;
```
#### 2)
```cpp
[[nodiscard]] constexpr std::vector<std::string_view> split(std::string_view string, char delimiter, bool discardEmpty = false) noexcept;
```

&nbsp;

## Example
```cpp
#include <print>
#include "xieite/strings/split.hpp"

int main() {
    for (std::string_view slice : xieite::strings::split("Hello, world!", ' ')) {
        std::println("{}", slice);
    }
}
```
Output:
```
Hello,
world!
```
