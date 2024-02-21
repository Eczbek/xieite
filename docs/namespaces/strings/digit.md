# [xieite](../../xieite.md)\:\:[strings](../../strings.md)\:\:digit
Defined in header [<xieite/strings/digit.hpp"](../../../include/xieite/strings/digit.hpp)

&nbsp;

## Description
Checks if a character is a digit.

&nbsp;

## Synopses
#### 1)
```cpp
[[nodiscard]] constexpr bool digit(char character) noexcept;
```

&nbsp;

## Example
```cpp
#include <iostream>
#include "xieite/strings/digit.hpp"

int main() {
    std::cout
        << std::boolalpha
        << xieite::strings::digit('3')
		<< '\n';
}
```
Output:
```
true
```
