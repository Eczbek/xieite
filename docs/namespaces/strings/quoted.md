# [xieite](../../xieite.md)\:\:[strings](../../strings.md)\:\:quoted
Defined in header [<xieite/strings/quoted.hpp>](../../../include/xieite/strings/quoted.hpp)

&nbsp;

## Description
Replicates `std::quoted` but without streams and more constexpr.

&nbsp;

## Synopsis
#### 1)
```cpp
[[nodiscard]] constexpr std::string quoted(std::string_view value, char delimiter = '"', char escape = '\\') noexcept;
```

&nbsp;

## Example
```cpp
#include <iostream>
#include "xieite/strings/quoted.hpp"

int main() {
    std::cout << xieite::strings::quoted("Something \"quoted\" and \\escaped") << '\n';
}
```
Output:
```
"Something \"quoted\" and \\escaped"
```
