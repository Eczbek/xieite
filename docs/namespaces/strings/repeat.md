# [xieite](../../xieite.md)\:\:[strings](../../strings.md)\:\:repeat
Defined in header [<xieite/strings/repeat.hpp"](../../../include/xieite/strings/repeat.hpp)

&nbsp;

## Description
Repeats a string multiple times.

&nbsp;

## Synopses
#### 1)
```cpp
[[nodiscard]] constexpr std::string repeat(std::size_t count, std::string_view string) noexcept;
```

&nbsp;

## Example
```cpp
#include <iostream>
#include "xieite/strings/repeat.hpp"

int main() {
    std::cout << xieite::strings::repeat("Hello, world!\n", 3);
}
```
Output:
```
Hello, world!
Hello, world!
Hello, world!
```
