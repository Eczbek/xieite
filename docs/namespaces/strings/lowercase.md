# [xieite](../../xieite.md)\:\:[strings](../../strings.md)\:\:lowercase
Defined in header [<xieite/strings/lowercase.hpp>](../../../include/xieite/strings/lowercase.hpp)

&nbsp;

## Description
Converts a string or character to lowercase. Only handles characters `A` to `Z`.

&nbsp;

## Synopses
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
#include <iostream>
#include <xieite/strings/lowercase.hpp>

int main() {
    std::cout << xieite::strings::lowercase("HELLO, WORLD!\n");
}
```
Output:
```
hello, world!
```