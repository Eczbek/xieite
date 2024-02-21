# [xieite](../../xieite.md)\:\:[strings](../../strings.md)\:\:after
Defined in header [<xieite/strings/after.hpp"](../../../include/xieite/strings/after.hpp)

&nbsp;

## Description
Takes the rest of a string after some substring.

&nbsp;

## Synopses
#### 1)
```cpp
[[nodiscard]] constexpr std::vector<std::string_view> after(std::string_view string, std::string_view start) noexcept;
```
#### 2)
```cpp
[[nodiscard]] constexpr std::vector<std::string_view> after(std::string_view string, char start) noexcept;
```

&nbsp;

## Example
```cpp
#include <iostream>
#include "xieite/strings/after.hpp"

int main() {
    std::cout << xieite::strings::after("Hello, world!", ' ') << '\n';
}
```
Output:
```
world!
```
