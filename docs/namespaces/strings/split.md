# [xieite](../../xieite.md)\:\:[strings](../../strings.md)\:\:split
Defined in header [<xieite/strings/split.hpp"](../../../include/xieite/strings/split.hpp)

&nbsp;

## Description
Splits a string by a delimiter.

&nbsp;

## Synopses
#### 1)
```cpp
[[nodiscard]] constexpr std::vector<std::string_view> split(std::string_view string, std::string_view delimiter) noexcept;
```
#### 2)
```cpp
[[nodiscard]] constexpr std::vector<std::string_view> split(std::string_view string, char delimiter) noexcept;
```

&nbsp;

## Example
```cpp
#include <iostream>
#include "xieite/strings/split.hpp"

int main() {
    for (std::string_view slice : xieite::strings::split("Hello, world!", ' ')) {
        std::cout << slice << '\n';
    }
}
```
Output:
```
Hello,
world!
```
