# [xieite](../../xieite.md)\:\:[strings](../../strings.md)\:\:lowercase\(\)
Defined in header [<xieite/strings/lowercase.hpp>](../../../include/xieite/strings/lowercase.hpp)

&nbsp;

## Description
Converts a string or character to lowercase. Only handles characters between `A` and `Z`.

&nbsp;

## Synopsis
#### 1)
```cpp
[[nodiscard]] constexpr char lowercase(char character) noexcept;
```
#### 2)
```cpp
[[nodiscard]] constexpr std::string lowercase(std::string_view string) noexcept;
```

&nbsp;

## Example
```cpp
#include <print>
#include "xieite/strings/lowercase.hpp"

int main() {
    std::println("{}", xieite::strings::lowercase("HELLO, WORLD!\n");
}
```
Output:
```
hello, world!
```
