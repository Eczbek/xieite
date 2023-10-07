# [xieite](../../xieite.md)\:\:[strings](../../strings.md)\:\:uppercase
Defined in header [<xieite/strings/uppercase.hpp>](../../../include/xieite/strings/uppercase.hpp)

&nbsp;

## Description
Converts a string or character to uppercase. Only handles characters `a` to `z`.

&nbsp;

## Synopses
#### 1)
```cpp
[[nodiscard]] constexpr char uppercase(char character) noexcept;
```
#### 2)
```cpp
[[nodiscard]] constexpr std::string uppercase(std::string_view string) noexcept;
```

&nbsp;

## Example
```cpp
#include <iostream>
#include <xieite/strings/uppercase.hpp>

int main() {
    std::cout << xieite::strings::uppercase("hello, world!\n");
}
```
Output:
```
HELLO, WORLD!
```
