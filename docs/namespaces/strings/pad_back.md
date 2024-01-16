# [xieite](../../xieite.md)\:\:[strings](../../strings.md)\:\:padBack
Defined in header [<xieite/strings/pad_back.hpp>](../../../include/xieite/strings/pad_back.hpp)

&nbsp;

## Description
Pads the back of a string.

&nbsp;

## Synopses
#### 1)
```cpp
[[nodiscard]] constexpr std::string padBack(const std::string& value, std::size_t size, char padding = ' ') noexcept;
```

&nbsp;

## Example
```cpp
#include <iostream>
#include <xieite/strings/pad_back.hpp>

int main() {
    std::cout << xieite::strings::padBack("BEEF", 7, '=') << '\n';
}
```
Output:
```
BEEF===
```
