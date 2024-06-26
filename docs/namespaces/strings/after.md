# [xieite](../../xieite.md)\:\:[strings](../../strings.md)\:\:after\(\)
Defined in header [<xieite/strings/after.hpp>](../../../include/xieite/strings/after.hpp)

&nbsp;

## Description
Takes the rest of a string after some substring.

&nbsp;

## Synopsis
#### 1)
```cpp
[[nodiscard]] constexpr std::string_view after(std::string_view string, std::string_view start) noexcept;
```
#### 2)
```cpp
[[nodiscard]] constexpr std::string_view after(std::string_view string, char start) noexcept;
```

&nbsp;

## Example
```cpp
#include <print>
#include "xieite/strings/after.hpp"

int main() {
    std::println("{}", xieite::strings::after("Hello, world!", ' '));
}
```
Output:
```
world!
```
