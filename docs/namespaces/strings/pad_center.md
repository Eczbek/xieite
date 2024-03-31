# [xieite](../../xieite.md)\:\:[strings](../../strings.md)\:\:padCenter\(\)
Defined in header [<xieite/strings/pad_center.hpp>](../../../include/xieite/strings/pad_center.hpp)

&nbsp;

## Description
Pads a string from both sides.

&nbsp;

## Synopsis
#### 1)
```cpp
[[nodiscard]] constexpr std::string padCenter(std::string_view value, std::size_t size, char padding = ' ', bool alignFront = true) noexcept;
```

&nbsp;

## Example
```cpp
#include <print>
#include "xieite/strings/pad_center.hpp"

int main() {
    for (int i = 3; i < 10; ++i) {
        std::println("|{}|", xieite::strings::padCenter("xyz", i));
    }
}
```
Output:
```
|xyz|
|xyz |
| xyz |
| xyz  |
|  xyz  |
|  xyz   |
|   xyz   |
```
