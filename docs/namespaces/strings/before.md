# [xieite](../../xieite.md)\:\:[strings](../../strings.md)\:\:before\(\)
Defined in header [<xieite/strings/before.hpp>](../../../include/xieite/strings/before.hpp)

&nbsp;

## Description
Takes the start of a string before some substring.

&nbsp;

## Synopsis
#### 1)
```cpp
[[nodiscard]] constexpr std::string_view before(std::string_view string, std::string_view end) noexcept;
```
#### 2)
```cpp
[[nodiscard]] constexpr std::string_view before(std::string_view string, char end) noexcept;
```

&nbsp;

## Example
```cpp
#include <print>
#include "xieite/strings/before.hpp"

int main() {
    std::println("{}", xieite::strings::before("Hello, world!", ' '));
}
```
Output:
```
Hello,
```
