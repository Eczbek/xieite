# [xieite](../../xieite.md)\:\:[strings](../../strings.md)\:\:padBack
Defined in header [<xieite/strings/pad_back.hpp>](../../../include/xieite/strings/pad_back.hpp)

&nbsp;

## Description
Pads the back of a string.

&nbsp;

## Synopsis
#### 1)
```cpp
[[nodiscard]] constexpr std::string padBack(const std::string& value, std::size_t size, char padding = ' ') noexcept;
```

&nbsp;

## Example
```cpp
#include <print>
#include "xieite/strings/pad_back.hpp"

int main() {
    std::println("{}", xieite::strings::padBack("BEEF", 7, '='));
}
```
Output:
```
BEEF===
```
